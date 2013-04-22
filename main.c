#include <p33FJ128MC802.h>
//#include <stdio.h>
//#include <libpic30.h>
//#include <delay.h>
#include "motors.h"
#include "config.h"
#include "main.h"

/* End Interrupt Definitions */
int main(void)
{
	RDY = DELAY_COUNT = 0;
	// initialize the mouse
	init_all();
	T4CONbits.TON = 1; // turn on timer 4
	while(!RDY){}
	
	// Turn on timers
    T1CONbits.TON = 1; // turn on timer 1
    T2CONbits.TON = 1; // turn on timer 2
	T4CONbits.TON = 0; // turn off timer 4

	ST_COUNT = 0;
    DIR =  TURN;
    while (1){}
}

