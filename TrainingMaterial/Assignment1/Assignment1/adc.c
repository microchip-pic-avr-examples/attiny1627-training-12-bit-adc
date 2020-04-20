/*
 * \file adc.c
 *
 * \brief ADC source file 
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

#include <avr/io.h>

#include "adc.h"

/********************************************************************ADC_init**************************************************************************************
Add code to initialize ADC here.
***************************************************************************************************************************************************************/
void adc_init()
{

}


uint16_t adc_get_sample(void)
{	/* Returns the outcome of an operation*/
	return ADC0.SAMPLE;		
}
uint32_t adc_get_result(void)
{	/* Depending on the ADC configuration, this returns a single sample or the sum of multiple accumulated samples*/
	return ADC0.RESULT;
}

bool adc_result_is_ready(void)
{
	return (ADC0.INTFLAGS & ADC_RESRDY_bm);
}
bool adc_sample_is_ready(void)
{
	return (ADC0.INTFLAGS & ADC_SAMPRDY_bm);
}