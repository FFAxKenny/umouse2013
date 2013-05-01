// functionality for getting binary walls
#include "walls.h"
#include "adc.h"
#include <stdbool.h>

bool left_wall(void) {
    // replace with flags later
    return (ADC_Sample(L_SENSOR) > LEFT_THRESHOLD);
}
bool front_wall(void) {
    // replace with flags later
    return ((ADC_Sample(RF_SENSOR) > RF_THRESHOLD) || (ADC_Sample(LF_SENSOR) > LF_THRESHOLD));
}
bool right_wall(void) {
    // replace with flags later
    return (ADC_Sample(R_SENSOR) > RIGHT_THRESHOLD);
}
