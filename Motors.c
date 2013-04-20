#include <p33FJ128MC802.h>
#include <stdio.h>
#include <libpic30.h>
#include <delay.h>
#include "Motors.h"

/* Initialize global variables */
int leftIndex = 0,
	rightIndex = 0;
const unsigned int leftSequence[] = {
    0x01, 
    0x02, 
    0x04, 
    0x08
};
const unsigned int rightSequence[] = { 
    0x08, 
    0x04, 
    0x02, 
    0x01
};

int DIR;

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    //  T1CONbits.TON = 0;   // turn off TMR1
    if(DIR == FORWARD)
    {	
        // pulse right motor forward
        rightIndex += 1;	
        rightIndex %= 4;
        PORTB = rightSequence[rightIndex];
    }
    else{	
        // pulse right motor reverse direction
        rightIndex += 3;	
        rightIndex %= 4;
        PORTB = rightSequence[rightIndex];
    }

    IFS0bits.T1IF = 0; // turn off TMR1 flag
    //	T1CONbits.TON = 1;

}
/* End Interrupt Definitions */
int main(void)
{
    // In order to configure the device to operate at 40 MHz, configure the PLL prescaler, 
    // PLL postscaler, and PLL divisor
    PLLFBD = 41; // M = PLLFBD + 2
    CLKDIVbits.PLLPOST = 0; // N1 = 2
    CLKDIVbits.PLLPRE = 0; // N2 = 2
    __builtin_write_OSCCONH(0x01); // New oscillator FRC w/ PLL
    __builtin_write_OSCCONL(0x01); // Enable clock switch as per dsPIC oscillator start-up 
    // guidelines. For more information, refer to 
    // Section 42. “Oscillator (Part IV)” (DS70307) in the 
    // “dsPIC33F Family Reference Manual”.
    while(OSCCONbits.COSC != 0b001); // Wait for the new Oscillator to become FRC w/ PLL
    while(OSCCONbits.LOCK != 1); // Wait for PLL to lock

    TRISB=0;
    AD1PCFGL = 0xFFFF;
    DIR =  FORWARD;

    //Set interrupt
    //	INTCON = 0xC0; //Enable Global,Timer0 Overflow interrupt
    INTCON1bits.NSTDIS = 1;  // disable nested interrupts
    // set 16 bit
    //	T1CONbits.RD16 = 1;
    // set up timer 1 prescaler for 1:2
    T1CONbits.TCKPS1 = 0;
    T1CONbits.TCKPS0 = 1;
    IPC0bits.T1IP2 = 1; // TMR 1 high priority
    IPC0bits.T1IP1 = 1; // TMR 1 high priority
    IPC0bits.T1IP0 = 1; // TMR 1 high priority
    IEC0bits.T1IE = 1; // enable the timer 1 interrupt
    IFS0bits.T1IF = 0; // turn off TMR1 flag
    T1CONbits.TCS = 0; // internal clock
    PR1=0x30FF;  // max speed using prescale 01
    T1CONbits.TON = 1; // turn on timer 1
    while (1){}



}

