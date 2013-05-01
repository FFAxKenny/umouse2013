// mouse.c
// functions for mouse
#include "direction.h"
#include "mouse.h"

// initialize the mouse
void init_mouse(Mouse * mouse) {
    mouse->x_pos = 0;
    mouse->y_pos = 0;
    mouse->c_dir = N;
}

// go forward
void go_f(Mouse * mouse) {
    switch(mouse->c_dir) {
        case N: mouse->y_pos = mouse->y_pos+1;
        case W: mouse->x_pos = mouse->x_pos-1;
        case S: mouse->y_pos = mouse->y_pos-1;
        case E: mouse->x_pos = mouse->x_pos+1;
        default: break;
    }
}

// turn left
void turn_l(Mouse * mouse) {
    mouse->c_dir = ((mouse->c_dir) + 1) % 4;
}

// turn right
void turn_r(Mouse * mouse) {
    mouse->c_dir = ((mouse->c_dir) - 1) % 4;
}

// turn uturn
void turn_u(Mouse * mouse) {
    mouse->c_dir = ((mouse->c_dir) + 2) % 4;
}
