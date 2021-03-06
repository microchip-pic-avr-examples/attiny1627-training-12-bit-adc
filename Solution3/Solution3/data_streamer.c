/*
 * \file data_stream.c
 *
 * \brief Data Stream source file 
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

#include "data_streamer.h"
#include "usart.h"

void transmit_to_DV()
{
	usart0_put_c(START);
	
	/* Original Sample */
	usart0_put_c((uint8_t)adc_t.adc_sample);
	usart0_put_c((uint8_t)(adc_t.adc_sample>>8));
	/* Filtered Result */
	usart0_put_c((uint8_t)adc_t.adc_average_result);
	usart0_put_c((uint8_t)(adc_t.adc_average_result>>8));
	usart0_put_c((uint8_t)(adc_t.adc_average_result>>16));
	usart0_put_c((uint8_t)(adc_t.adc_average_result>>24));
	/* High Resolution Result*/
	usart0_put_c((uint8_t)adc_t.adc_high_res_result);
	usart0_put_c((uint8_t)(adc_t.adc_high_res_result>>8));
	usart0_put_c((uint8_t)(adc_t.adc_high_res_result>>16));
	usart0_put_c((uint8_t)(adc_t.adc_high_res_result>>24));
	
	usart0_put_c(END);
}