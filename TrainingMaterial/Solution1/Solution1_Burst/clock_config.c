/*
 * clock_config.c
 *
 * Created: 25.02.2020 13:06:21
 *  Author: M52653
 */ 
#include <avr/io.h>
#include "clock_config.h"

/********************************************************************SYS_init**************************************************************************************
CPU clock : 10 MHz
This is done in the CLKCTRL.MCLKCTRLB register. However, it is protected by Configuration Change Protection. This means in order to change settings in this
register, a specific routine must be followed, involving loading a signature value into the CCP register and then applying settings within a defined number of cycles. This process is abstracted in a
macro, _PROTECTED_WRITE(), provided in header file which is included by default in projects configured for devices using CCP.
***************************************************************************************************************************************************************/

void clock_init()
{
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, CLKCTRL_PEN_bm | CLKCTRL_PDIV_2X_gc);	//10MHz main clk	
	
}