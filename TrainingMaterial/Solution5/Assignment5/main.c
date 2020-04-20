/*
 * \file main.c
 *
 * \brief Main source file 
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

#define F_CPU 10000000ul

#include <avr/io.h>
#include <math.h>
#include <stdbool.h>
#include <util/delay.h>
#include <stdlib.h>

#include "clock_config.h"
#include "io.h"
#include "usart.h"
#include "adc.h"
#include "data_streamer.h"

#define ADC_MAX_VALUE	(((1 << 12) / 2) - 1) /* In differential mode, the max value is 2047 */

/* Volatile variables to improve debug experience */
static volatile int16_t adc_reading;
static volatile float voltage;


int main(void)
{
	clock_init();
	io_init();
	adc_init();
	usart0_init();
	
    /* Replace with your application code */
	ADC0.COMMAND |= ADC_START_IMMEDIATE_gc;
    while (1) 
    {
		/* Only used for debugging */
// 		PORTB.OUTTGL = LED0_bm;
// 		_delay_ms(200);
		
		if (adc_result_is_ready()) /* Check if ADC result is ready*/
		{
			/* Only used for debugging */
// 			adc_reading = adc_get_sample();
// 			voltage = (float)((adc_reading * 2.048) /ADC_MAX_VALUE);
			 
			adc_t.adc_sample = adc_get_sample();
			
			/* Formula shows how much MUXPOS and MUXNEG differ from each other in Volt */
			adc_t.adc_differential_volt = (float)((adc_t.adc_sample * 2.048) / ADC_MAX_VALUE);
			
			transmit_to_DV();
		}
		
    }
}
