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
	// initialize the mouse
	init_all();

    DIR =  FORWARD;
    while (1){}
}

