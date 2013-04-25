#include <p33FJ128MC802.h>
//#include <stdio.h>
//#include <libpic30.h>
//#include <delay.h>
#include "motors.h"
#include "config.h"
#include "main.h"
#include "adc.h"
#include "track.h"

/* End Interrupt Definitions */
int main(void)
{
    int ADCValue = 0;
	int L_TIME = PR1_MAP,
		R_TIME = PR1_MAP;
	// initialize the mouse
	init_all();

    while (1){

		//Convert
		ADCValue = ADC_Sample();

		if(ADCValue > BL_MID+BL_DELTA)	// If too close
		{	
			R_TIME += PR1_CORRECT;
			L_TIME -= PR2_CORRECT;
			PR1 = R_TIME;
			PR2 = L_TIME;
			if (L_TIME < PR2_MAP-PR2_TRACK) L_TIME =PR2_MAP-PR2_TRACK;
			if(R_TIME >  PR1_MAP) R_TIME = PR1_MAP;
		}
		else if(ADCValue < BL_MID-BL_DELTA)	// If too far
		{
			R_TIME -= PR1_CORRECT;
			L_TIME += PR2_CORRECT;
			PR1 = R_TIME;
			PR2 = L_TIME;
			if (R_TIME < PR1_MAP-PR1_TRACK) R_TIME = PR1_MAP-PR1_TRACK;
			if(L_TIME >  PR2_MAP) L_TIME = PR2_MAP;
		}
		else {
			R_TIME = PR1_MAP;
			L_TIME = PR2_MAP;
		}
	}
}

