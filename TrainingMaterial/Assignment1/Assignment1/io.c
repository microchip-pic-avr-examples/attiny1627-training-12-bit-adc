/*
 * \file io.c
 *
 * \brief IO source file 
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
#include "io.h"

/********************************************************************IO_init**************************************************************************************
Initializes IO pin directions.

*****Output*****
Pin PB2 : USART0 (EDBG)TXD : output direction
Pin PB7 : LED0  :  output direction

*****Input*****

Pin PA5 : ADC analog channel 5 : digital input buffer disabled.//AN3 on adapter

***************************************************************************************************************************************************************/
void io_init(void)
{
	PORTB.DIRSET = USART0_TX_bm | LED0_bm;
	
	PORTA.PIN5CTRL |= PORT_ISC_INPUT_DISABLE_gc; //PA5 analog
	
	PORTB.OUTCLR |= LED0_bm; 
}
