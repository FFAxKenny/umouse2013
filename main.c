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
    int ADCValue = 0;
	int L_TIME = PR1_MAX,
		R_TIME = PR1_MAX;
	// initialize the mouse
	init_all();

    while (1){

        //Convert

        AD1CON1bits.SAMP = 1;           // Start Conversion
        ADC1BUF0 = 0x0000;              // Clear ADC1 Buffer
        while (!AD1CON1bits.DONE);      // Conversion done? Waiting for 1
        AD1CON1bits.DONE = 0;           // Clear conversion done status bit
        ADCValue = ADC1BUF0;

   //     if(ADCValue > 2000) DIR = STOP;
     //   else DIR = TURN;
	
	if(ADCValue > 3150)
		{	
			R_TIME += 1;L_TIME -= 1;
			PR1 = R_TIME; PR2 = L_TIME;
			if (L_TIME < 0x30CC) L_TIME =0x30CC;
			if(R_TIME >  0x40CC) R_TIME = 0x40CC;
		}
		else if(ADCValue < 3090)
		{
			R_TIME -= 1;L_TIME += 1;
			PR1 = R_TIME; PR2 = L_TIME;
			if (R_TIME < 0x30CC) R_TIME =0x30CC;
			if(L_TIME >  0x40CC) L_TIME = 0x40CC;
		}
		else R_TIME = L_TIME = PR1_MAX;
    }
}

