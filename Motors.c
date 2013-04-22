// contains functions for configuration
// and initialization

#include <p33FJ128MC802.h>
#include "main.h"
#include "motors.h"

int DIR;

// Use timer 1 for right motor
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    //  T1CONbits.TON = 0;   // turn off TMR1
    if(DIR == FORWARD)
    {	
        // pulse right motor forward
		R_IND += 1;	
        R_IND %= 4;
        PORTB = (PORTB & RS_AND) + R_SEQ[R_IND];
    }
    else{	
        // pulse right motor reverse direction
        R_IND += 3;	
        R_IND %= 4;
        PORTB = (PORTB & RS_AND) + R_SEQ[R_IND];
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
        L_IND += 1;	
        L_IND %= 4;
        PORTB = (PORTB & LS_AND) + L_SEQ[L_IND];
    }
    else{	
        // pulse left motor reverse direction
        L_IND += 3;	
        L_IND %= 4;
        PORTB = (PORTB & LS_AND) + L_SEQ[L_IND];
    }

    IFS0bits.T2IF = 0; // turn off TMR2 flag
    //	T2CONbits.TON = 1;

}
