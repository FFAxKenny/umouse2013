#include <p33FJ128MC802.h>
//#include <stdio.h>
//#include <libpic30.h>
//#include <delay.h>
#include "Motors.h"
#include "config.h"

/* Initialize global variables */
int leftIndex = 0,
	rightIndex = 0;
const unsigned int leftSequence[] = {
	LS_0, 
	LS_1, 
	LS_2, 
	LS_3
};
const unsigned int rightSequence[] = { 
	RS_0,
	RS_1,
	RS_2,
	RS_3
};

int DIR;

// Use timer 1 for right motor
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    //  T1CONbits.TON = 0;   // turn off TMR1
    if(DIR == FORWARD)
    {	
        // pulse right motor forward
        rightIndex += 1;	
        rightIndex %= 4;
        PORTB = (PORTB & RS_AND) + rightSequence[rightIndex];
    }
    else{	
        // pulse right motor reverse direction
        rightIndex += 3;	
        rightIndex %= 4;
        PORTB = (PORTB & RS_AND) + rightSequence[rightIndex];
    }

    IFS0bits.T1IF = 0; // turn off TMR1 flag
    //	T1CONbits.TON = 1;

}

// Use timer 2 for left motor
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{
    //  T2CONbits.TON = 0;   // turn off TMR1
    if(DIR == FORWARD)
    {	
        // pulse left motor forward
        leftIndex += 1;	
        leftIndex %= 4;
        PORTB = (PORTB & LS_AND) + leftSequence[leftIndex];
    }
    else{	
        // pulse left motor reverse direction
        leftIndex += 3;	
        leftIndex %= 4;
        PORTB = (PORTB & LS_AND) + leftSequence[leftIndex];
    }

    IFS0bits.T2IF = 0; // turn off TMR2 flag
    //	T2CONbits.TON = 1;

}
/* End Interrupt Definitions */
int main(void)
{
	// initialize the mouse
	init_all();

    DIR =  FORWARD;
    while (1){}
}

