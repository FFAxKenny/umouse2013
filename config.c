// contains functions for configuration
// and initialization

#include <p33FJ128MC802.h>
#include "config.h"
#include "main.h"
#include "motors.h"
#include "adc.h"

int L_IND;
int R_IND;

unsigned int L_SEQ[4];
unsigned int R_SEQ[4];

int DELAY_COUNT; //counter for delay
int RDY;// flag for when mouse is ready

int ST_COUNT;  // counter for steps
int DIR; // direction

// initialize the mouse
void init_all(void) {
	// initialize global variables
	init_globals();

	// initialize clock
	init_clock();

	// configure interrupts
	config_interrupts();

	// configure I/O
	config_io();

    // initialize ADC
    ADC_Init();
}

// initialize global variables
void init_globals(void) {
	/* Initialize global variables */
	// Indices
	L_IND = 0;
	R_IND = 0;

	// Sequences
	L_SEQ[0] =	LS_0;
	L_SEQ[1] =	LS_1;
	L_SEQ[2] =	LS_2;
	L_SEQ[3] =	LS_3;

	R_SEQ[0] =	RS_0;
	R_SEQ[1] =	RS_1;
	R_SEQ[2] =	RS_2;
	R_SEQ[3] =	RS_3;

	// Delay count
	DELAY_COUNT = 0;

	// Ready
	RDY = 0;

	// Step count
	ST_COUNT = 0;

	// Direction
	DIR = FORWARD;
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
	
	// set 16 bit
    // set up timer 4 prescaler for 1:256
    T4CONbits.TCKPS1 = 1;
    T4CONbits.TCKPS0 = 1;
    IPC6bits.T4IP2 = 1; // TMR 4 high priority
    IPC6bits.T4IP1 = 1; // TMR 4 high priority
    IPC6bits.T4IP0 = 1; // TMR 4 high priority
    IEC1bits.T4IE = 1; // enable the timer 4 interrupt
    IFS1bits.T4IF = 0; // turn off TMR4 flag
    T4CONbits.TCS = 0; // internal clock

	// start timers

	T4CONbits.TON = 1; 	// turn on timer 4
	while(!RDY){}		// use timer 4 to delay startup
	
	// Turn on timers
    T1CONbits.TON = 1; // turn on timer 1
    T2CONbits.TON = 1; // turn on timer 2
	T4CONbits.TON = 0; // turn off timer 4

}

// wait to start the timers
// Use timer 4 for delay/counting
void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void)
{
    DELAY_COUNT ++;
	if(DELAY_COUNT == 5) { // delays 2.5s
		RDY = 1;
	}

    IFS1bits.T4IF = 0; // turn off TMR2 flag
   // PR4=PR4_MAX;  // max speed using prescale 01
	
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
	TRISA=0b11;
	TRISB=0x0003;
    AD1PCFGL = 0xFFFF;
}
