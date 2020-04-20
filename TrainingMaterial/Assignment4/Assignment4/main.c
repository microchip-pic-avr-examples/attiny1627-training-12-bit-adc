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
	
	
	
	ADC0.COMMAND = ADC_MODE_SINGLE_12BIT_gc; /* Single 12-bit mode */
}

int main(void)
{
	adc_init();

	

	while(1)
	{
		ADC0.COMMAND |= ADC_START_IMMEDIATE_gc;     /* Start ADC conversion */
		while(!(ADC0.INTFLAGS & ADC_RESRDY_bm));   /* Wait until conversion is done */

		/* Calibration compensation as explained in the data sheet */
		/*<----- Add temperature calculations here*/
		
		

		_delay_ms(500);
	}
}
