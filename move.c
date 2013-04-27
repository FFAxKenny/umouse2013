// move.c
// move the mouse
#include <p33FJ128MC802.h>
#include "adc.h"
#include "main.h"
#include "motors.h"
#include "move.h"
#include "decide.h"
#include "config.h"

// Correct off of front wall
void correct(void) {
    // nothing yet
}

// Turn with direction from decide.c
void turn(int direction) {
    // change the direction of the motors
    switch(direction) {
        case L_TURN:
            DIR = LEFT;
            break;
        case R_TURN:
            DIR = RIGHT;
            break;
        case U_TURN:
            DIR = TURN;
            break;
        case NO_TURN:
            break;
        default:
            break;
    }

    // wait for the turn to finish
    while(DIR != STOP);
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
    int sensor = 0;
    int i = 0; // counter for adc sampling
    int avgADC = 0;  // sample 3 times and take average
//    int fADC = 0; // average front wall detect
//    int FFLAG = 0; // front wall flag
	int P = 3;

    while(DIR != STOP) {
        avgADC = 0;
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
            if(totalError < -100 || avgADC < 1000)  //stop using right
            {
                sensor = 1;  // switch sensor
                totalError = 0; // dont change the motor speed
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
            if(totalError < -100 || avgADC < 1000)  // stop using left
            {
                sensor = 0;
                totalError = 0;
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
//            if(STEP == 190)  // this is for front wall detect
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
    }
}

