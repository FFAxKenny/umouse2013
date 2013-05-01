// mouse.c
// functions for mouse
#include "direction.h"
#include "decide.h"
#include "mouse.h"
#include <stdlib.h>

// initialize the mouse
void init_mouse(Mouse * mouse) {
    mouse->x_pos = 0;
    mouse->y_pos = 0;
    mouse->c_dir = N;
}

// go forward
void go_f(Mouse * mouse) {
    switch(mouse->c_dir) {
        case N:
			mouse->y_pos = mouse->y_pos+1;
			break;
        case W:
			mouse->x_pos = mouse->x_pos-1;
			break;
        case S:
			mouse->y_pos = mouse->y_pos-1;
			break;
        case E:
			mouse->x_pos = mouse->x_pos+1;
			break;
        default: break;
    }
}

// turn left
void go_turn(Mouse * mouse, int turn) {
	switch(turn) {
		case L_TURN:
			mouse->c_dir = ((mouse->c_dir) + 1) % 4;	// left
			break;
		case R_TURN:
			mouse->c_dir = ((mouse->c_dir) + 3) % 4;	// right
			break;
		case U_TURN:
			mouse->c_dir = ((mouse->c_dir) + 2) % 4;	// uturn
			break;
		default:
			break;
	}
}
