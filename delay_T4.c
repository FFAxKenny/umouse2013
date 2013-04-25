#include <p33FJ128MC802.h>
#include "main.h"
#include "delay_T4.h"

void delay_T4(int max_delay) {
    MAX_DELAY = max_delay;
    DELAY_COUNT = 0;
    RDY = 0;
    T4CONbits.TON = 1;  // turn on timer 4
    while(!RDY){}       // use timer 4 to delay
    T4CONbits.TON = 0;  // turn off timer 4
}
