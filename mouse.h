#ifndef MOUSE_H
#define MOUSE_H
typedef struct {
    // cardinal direction
    int c_dir;

    // position
    int x_pos;
    int y_pos;
} Mouse;

// initialize mouse
void init_mouse(Mouse * mouse);

// go forward
void go_f(Mouse * mouse);

// turn left/right/uturn
void go_turn(Mouse * mouse, int direction);
#endif
