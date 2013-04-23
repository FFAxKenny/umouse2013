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
        //ADCON1 Register
        //Set up A/D for Automatic Sampling
        //Use internal counter (SAMC) to provide sampling time
        //Set up A/D conversrion results to be read in 1.15 fractional
        //number format.
        //Set up Sequential sampling for multiple S/H amplifiers
        //All other bits to their default state
        AD1CON1bits.FORM = 3;
        AD1CON1bits.SSRC = 7;
        AD1CON1bits.ASAM = 1;
        AD1CON1bits.SIMSAM = 0;
//		AD1CON1bits.AD12B = 0; //4 channel 10 bit

        //ADCON2 Register
        //Set up A/D for interrupting after 2 samples get filled in the buffer
        //Set up to sample on 2 S/H amplifiers - CH0 and CH1
        //All other bits to their default state
        AD1CON2bits.SMPI = 0; // edited to increment after 1
        AD1CON2bits.CHPS = 0;
	//ADCON2bits.VCFG = 3; //Ideally use external references

        //ADCON3 Register
        //We would like to set up a sampling rate of 1 MSPS
        //Total Conversion Time= 1/Sampling Rate = 125 microseconds
        //At 29.4 MIPS, Tcy = 33.9 ns = Instruction Cycle Time
        //The A/D converter will take 12*Tad periods to convert each sample
        //So for ~1 MSPS we need to have Tad close to 83.3ns
        //Using equaion in the Family Reference Manual we have
        //ADCS = 2*Tad/Tcy - 1
		
		AD1CON3bits.ADRC=0;			// ADC Clock is derived from Systems Clock
        AD1CON3bits.SAMC = 0; // 0*Tad
        AD1CON3bits.ADCS = 2;

        //ADCHS Register
        //Set up A/D Channel Select Register to convert AN3 on Mux A input
        //of CH0 and CH1 S/H amplifiers
        AD1CHS0 = 0x0000;
		//AD1CHS0bits.CH0SA = 0; // MUXA +ve input selection (AIN0) for CH0
		//AD1CHS0bits.CH0NA = 0; // MUXA -ve input selection (VREF-) for CH0


        //ADCSSL Register
        //Channel Scanning is disabled. All bits left to their default state
      //  ADCSSL = 0x0000;
	//	AD1CON2bits.CSCNA = 0;
		

        //ADPCFG Register
        //Set up channels AN7 as analog input and configure rest as digital
        //Recall that we configured all A/D pins as digital when code execution
        //entered main() out of reset
	AD1PCFGL = 0xFFFE;
		AD1PCFGLbits.PCFG0 = 0; // AN0 as Analog Input
    //    ADPCFGbits.PCFG3 = 0;

        //Clear the A/D interrupt flag bit
        IFS0bits.AD1IF = 0;

        //Set the A/D interrupt enable bit
        IEC0bits.AD1IE = 0;

        //Turn on the A/D converter
        //This is typically done after configuring other registers
        AD1CON1bits.ADON = 1;

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

