// contains functions for configuration
// and initialization

#include <p33FJ128MC802.h>
#include "config.h"

// initialize the mouse
void init_all(void) {
	// initialize clock
	init_clock();

	// configure interrupts
	config_interrupts();

	// configure I/O
	config_io();
}

// configure interrupts
void config_interrupts(void) {
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
    PR1=PR1_MAX;  // max speed using prescale 01
    T1CONbits.TON = 1; // turn on timer 1

    // set 16 bit
    //	T2CONbits.RD16 = 1;
    // set up timer 2 prescaler for 1:2
    T2CONbits.TCKPS1 = 0;
    T2CONbits.TCKPS0 = 1;
    IPC1bits.T2IP2 = 1; // TMR 1 high priority
    IPC1bits.T2IP1 = 1; // TMR 1 high priority
    IPC1bits.T2IP0 = 1; // TMR 1 high priority
    IEC0bits.T2IE = 1; // enable the timer 1 interrupt
    IFS0bits.T2IF = 0; // turn off TMR1 flag
    T2CONbits.TCS = 0; // internal clock
    PR2=PR2_MAX;  // max speed using prescale 01
    T2CONbits.TON = 1; // turn on timer 1
}

// configure clock
void init_clock(void) {
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
}

// configure io
void config_io(void) {
	TRISB=0;
    AD1PCFGL = 0xFFFF;
}
