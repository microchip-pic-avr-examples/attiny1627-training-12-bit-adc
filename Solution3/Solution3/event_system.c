/*
 * \file event_system.c
 *
 * \brief Event System source file 
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


/********************************************************************EVENT_SYSTEM_init**************************************************************************************
RTC and the event system as an ADC sample trigger.
Event System Channel 0:		Event system generator: RTC Overflow
							Event system user: ADC0
***************************************************************************************************************************************************************/

#include "event_system.h"

void event_system_init(void)
{
	EVSYS.CHANNEL0 = EVSYS_CHANNEL0_RTC_OVF_gc; /* Real Time Counter overflow */
	EVSYS.USERADC0START = EVSYS_USER_CHANNEL0_gc; /* Asynchronous Event Channel 0 */
	EVSYS.USEREVSYSEVOUTA = EVSYS_USER_CHANNEL0_gc; //See evsys out
}