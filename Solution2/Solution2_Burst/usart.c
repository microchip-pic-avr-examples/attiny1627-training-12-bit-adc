/*
 * \file usart.c
 *
 * \brief USART source file 
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
#include <stdbool.h>
#define BAUD_RATE  115200
#include "clock_config.h"



/********************************************************************USART_init**************************************************************************************
Initializes USART
EDBG virtual come port is connected to USART0 on nano PB2,PB3
Baud Rate : 115200
********************************************************************************************************************************************************/
void usart0_init()
{
	USART0.CTRLB = USART_TXEN_bm;
	USART0.BAUD = (F_CPU * 64.0) / (BAUD_RATE * 16.0);
	
}

/********************************************************************usart0_put_c**************************************************************************************
Transmit data through USART
***************************************************************************************************************************************************************/

void usart0_put_c(uint8_t c)
{
	while (!(USART0.STATUS & USART_DREIF_bm));
	USART0.TXDATAL = c;
}


