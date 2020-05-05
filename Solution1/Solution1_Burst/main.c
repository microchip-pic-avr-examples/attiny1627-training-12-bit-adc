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


int main(void)
{
	clock_init();
	io_init();
	adc_init();
	usart0_init();

	ADC0.COMMAND |= ADC_START_IMMEDIATE_gc; //start free running
	
	while (1)
	{
		/* Only used for debugging */
// 		PORTB.OUTTGL = LED0_bm;
// 		_delay_ms(100);
 		if(adc_result_is_ready())
		{   
			adc_t.adc_sample = adc_get_sample();	// Original Signal
			adc_t.adc_result = adc_get_result();	// Filtered Signal

			adc_t.adc_average_result = adc_t.adc_result>>ADC_SAMPLES;	// Burst
			
			transmit_to_DV();
			/* Since the data is transmitted in quick succession, it is good to add some delay between each measurement */
			
		}
	}
}

