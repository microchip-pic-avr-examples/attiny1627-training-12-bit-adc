/*
 * \file main.c
 *
 * \brief How To Use the 12-Bit Differential ADC in Single Mode
 *
 *  (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 *  Subject to your compliance with these terms,you may use this software and
 *  any derivatives exclusively with Microchip products.It is your responsibility
 *  to comply with third party license terms applicable to your use of third party
 *  software (including open source software) that may accompany Microchip software.
 *
 *  THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 *  EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 *  WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 *  PARTICULAR PURPOSE.
 *
 *  IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 *  INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 *  WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 *  BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 *  FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 *  ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 *  THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 */


/*
 *
 * How To Use the 12-Bit Differential ADC in Single Mode:
 * Measuring Temperature
 *
 */

#define F_CPU 3333333ul


#include <avr/io.h>
#include <math.h>
#include <util/delay.h>

#define TIMEBASE_VALUE ((uint8_t) ceil(F_CPU*0.000001))
#define TEMPSENSE_SAMPDUR ((uint8_t) ceil(F_CPU*0.000032/2)) /* SAMPDUR for TEMPSENSE must be >= 32 µs * f_ADC ~= 32 µs * 1.67 MHz ~= 54 */

/* Volatile variables to improve debug experience */
static volatile uint16_t adc_reading;
static volatile uint16_t temperature_in_K;
static volatile int16_t temperature_in_degC;

/*********************************************************************************
ADC initialization
**********************************************************************************/
void adc_init()
{
	ADC0.CTRLA = ADC_ENABLE_bm;
	ADC0.CTRLB = ADC_PRESC_DIV2_gc; /* fCLK_ADC = 3.333333/2 MHz */
	ADC0.CTRLC = ADC_REFSEL_1024MV_gc | (TIMEBASE_VALUE << ADC_TIMEBASE_gp);
	ADC0.CTRLE = TEMPSENSE_SAMPDUR;

	ADC0.MUXPOS = ADC_MUXPOS_TEMPSENSE_gc; /* ADC Internal Temperature Sensor */
	ADC0.COMMAND = ADC_MODE_SINGLE_12BIT_gc; /* Single 12-bit mode */
}

int main(void)
{
	adc_init();

	int8_t sigrow_offset = SIGROW.TEMPSENSE1;  /* Read signed offset from signature row */
	uint8_t sigrow_gain = SIGROW.TEMPSENSE0;    /* Read unsigned gain/slope from signature row */

	while(1)
	{
		ADC0.COMMAND |= ADC_START_IMMEDIATE_gc;     /* Start ADC conversion */
		while(!(ADC0.INTFLAGS & ADC_RESRDY_bm));   /* Wait until conversion is done */

		/* Calibration compensation as explained in the data sheet */
		adc_reading = ADC0.RESULT >> 2; /* 10-bit MSb of ADC result with 1.024V internal reference */
		uint32_t temp = adc_reading - sigrow_offset;
		
		temp *= sigrow_gain; /* Result might overflow 16-bit variable (10-bit + 8-bit) */
		temp += 0x80; /* Add 256/2 to get correct integer rounding on division below */
		temp >>= 8; /* Divide result by 256 to get processed temperature in Kelvin */
		temperature_in_K = temp;
		temperature_in_degC = temperature_in_K - 273;

		_delay_ms(500);
	}
}
