/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        ADC.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC30Fxxxx
* Compiler:        MPLAB® C30 v1.32.00 or higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Inc. (“Microchip”) licenses this software to you
* solely for use with Microchip dsPIC® digital signal controller
* products. The software is owned by Microchip and is protected under
* applicable copyright laws.  All rights reserved.
*
* SOFTWARE IS PROVIDED “AS IS.”  MICROCHIP EXPRESSLY DISCLAIMS ANY
* WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP
* BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
* DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
* PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
* BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
* ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Hrushikesh Vasuki 07/29/05  First release of source file
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* This file contains two functions - ADC_Init() and _ADCInterrupt().
*
**********************************************************************/

#include <p33FJ128MC802.h>

unsigned int ADResult1 = 0;
unsigned int ADResult2 = 0;



//Functions:
//ADC_Init() is used to configure A/D to convert 16 samples of 1 input
//channel per interrupt. The A/D is set up for a sampling rate of 1MSPS
//Timer3 is used to provide sampling time delay.
//The input pin being acquired and converted is AN7.
void ADC_Init(void)
{
    AD1CON1 = 0x04E0;                   // A/D Control Register 1
    AD1CON2 = 0x0000;                   // A/D Control Register 2
    AD1CON3bits.SAMC = 0b11000;         // A/D Control Register 3
    AD1CON3bits.ADCS = 8;
    AD1CON4 = 0x0000;                   // A/D Control Register 4

   	AD1CHS0bits.CH0SA = 1;
	AD1CHS0bits.CH0NA = 0;
	AD1PCFGL = 0xFFFF;
	AD1PCFGLbits.PCFG0 = 0; // AN0 as Analog Input
	AD1PCFGLbits.PCFG1 = 0; // AN1 as Analog Input
	AD1PCFGLbits.PCFG2 = 0; // AN2 as Analog Input
	AD1PCFGLbits.PCFG3 = 0; // AN3 as Analog Input
    AD1CON1bits.ADON = 1;               // Begin Sampling Sequence

}

int ADC_Sample(int an_sel) {
	AD1CHS0bits.CH0SA = an_sel;
	AD1CON1bits.SAMP = 1;           // Start Conversion
	ADC1BUF0 = 0x0000;              // Clear ADC1 Buffer
	AD1CON1bits.SAMP = 0;           // Start Conversion
	while (!AD1CON1bits.DONE);      // Conversion done? Waiting for 1
	AD1CON1bits.DONE = 0;           // Clear conversion done status bit
	return ADC1BUF0;
}

//_ADCInterrupt() is the A/D interrupt service routine (ISR).
//The routine must have global scope in order to be an ISR.
//The ISR name is chosen from the device linker script.
//void __attribute__((__interrupt__)) _ADC1Interrupt(void)
/*
void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void)
{
	ADResult1 = ADC1BUF0;
//	ADResult2 = ADCBUF1;
	
        //Clear the A/D Interrupt flag bit or else the CPU will
        //keep vectoring back to the ISR
        IFS0bits.AD1IF = 0;
	
        
}
*/

