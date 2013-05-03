// move.c
// move the mouse
#include <stdbool.h>
#include <p33FJ128MC802.h>
#include "adc.h"
#include "main.h"
#include "motors.h"
#include "move.h"
#include "decide.h"
#include "config.h"
#include "delay_T4.h"

void stop(void) {
	DIR = STOP;
	delay_T4(2);
}
int avg_adc(int sensor)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int read[3];

	for(i=0;i<3;i++)
	{	
		//Convert
		read[i] = ADC_Sample(sensor);
	}
    // the following two loops sort the array x in ascending order
    for(i=0; i<2; i++) {
        for(j=i+1; j<2; j++) {
            if(read[j] < read[i]) {
                // swap elements
                temp = read[i];
                read[i] = read[j];
                read[j] = temp;
            }
        }
    }
        // else return the element in the middle
        return read[1];
}
// Turn with direction from decide.c
int turn(int direction) {
    // change the direction of the motors
    switch(direction) {
        case L_TURN:
			stop();
            DIR = LEFT;
            break;
        case R_TURN:
			stop();
            DIR = RIGHT;
            break;
        case U_TURN:
			stop();
            DIR = TURN;
            break;
        case NO_TURN:
            break;
        default:
            break;
    }

    // wait for the turn to finish
    while(DIR != STOP);
    // stop the mouse if not going straight
	if(direction != NO_TURN) stop();

    return direction;
}

// Go forward 1 cell
void track(void) {
    // Change direction to forward
    DIR = FORWARD;

    int ADCValue = 0;
    int errorP = 0;
    int	errorD = 0;
    int	totalError = 0;
    int	oldErrorP = 0;
    int i = 0; // counter for adc sampling
    int avgADC = 0;  // sample 3 times and take average
    int fADC = 0; // average front wall detect
//    int FFLAG = 0; // front wall flag

//	float P = 2;
float P = 11;     //7
float D = 20;    //20

    while(DIR == FORWARD) {
/*        avgADC = 0;
        for(i=0;i<3;i++)
        {   
            //Convert
            ADCValue = ADC_Sample(sensor);
            avgADC += ADCValue;
        }
        avgADC /= 3;

        if(sensor == 0) // using right sensor
        {
            // this is value when mouse is centered
            errorP = (avgADC - 3303);
            errorD = errorP - oldErrorP; // derivative not used
            totalError = P*errorP; // + D*errorD); // derivative not used
            // P = 3 right now
            oldErrorP = errorP;
            // give tolerance around middle
            if(avgADC > 3250 && avgADC < 3350)
                totalError = 0;
            // if avgADC< 1000 means no wall on right side
            // total error < -100 means mouse is left of center
            //needs to push off left wall now
            //(this needs to be clarified maybe ask tyler)
            if(totalError < -100)  //stop using right
            {
                sensor = 1;  // switch sensor
                totalError = 0; // dont change the motor speed
            }
			else if (avgADC < 1000)  {
                sensor = 1;  // switch sensor
                totalError = -1000; // dont change the motor speed
			}
        }
        else  // using left sensor same thing
        {
            errorP = avgADC - 2100; // DONT CHANGE
            errorD = errorP - oldErrorP;
            totalError = P*errorP; // + D*errorD);
            oldErrorP = errorP;
            if(totalError > 2000) totalError = 2000; // cap
            // 2136 for LEFT SENSOR
            if(totalError < -100)  // stop using left
            {
                sensor = 0;
                totalError = 0;
            } 
            else if(avgADC < 1000)  // stop using left
            {
                sensor = 0;
                totalError = -1000;
            } 
            if(avgADC > 2000 && avgADC < 2200)
                totalError = 0;
            totalError *= -1;
        }
        PR1=PR1_MAP - totalError;
        PR2=PR1_MAP + totalError;
        // ***** THIS IS WHERE YOU BREAK POINT FOR DEBUG *
        // then you can keep pressing play and read values for sensor
        // remember to look at these values
        // ADCValue totalError      avgADC  sensor
//            if(ST_COUNT >= 180 && ST_COUNT % 4 == 0)  // this is for front wall detect
//            {
//                fADC = 0;
//                for(i=0;i<3;i++)
//                {   
//                    //Convert
//                    ADCValue = ADC_Sample(2);
//                    fADC += ADCValue;
//                }
//                fADC /= 3;
//                if(fADC > 1000) FFLAG = 1;
//                else FFLAG = 0;
//            }

*/
if(ST_COUNT % 3 == 0) {
	avgADC = avg_adc(0);
	if(avgADC > 3100)  // 3100 only push off 
		errorP = (avgADC - 3250)/2; //3303
	else 
	{
		avgADC = avg_adc(1);
		if(avgADC > 1500)  // 1500 left sensor
			errorP = (1850 - avgADC)/2; //2100
		else errorP = 0;
	}
	
    	errorD = errorP - oldErrorP;
		totalError = (P*errorP + D*errorD);
		if(errorP > -20 && errorP < 20) totalError = 0;
    	oldErrorP = errorP;
	
		
	PR1=PR1_MAP - totalError;
    PR2=PR1_MAP + totalError;
	}   
	
/*	fADC = 0;
	for(i=0;i<3;i++)
	{	
		//Convert
		ADCValue = ADC_Sample(2);
		fADC += ADCValue;
	}
	fADC /= 3;
	if(fADC > 3900) ST_COUNT = F_STEP; // 3800 
	if(ST_COUNT == F_STEP)  // when enough steps are taken
	{
		DIR = STOP;		// stop turning
		ST_COUNT=0;		// reset turn count
		PR1 = PR1_MAP;
		PR2 = PR1_MAP;
    }
*/
}
}

