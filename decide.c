// decide.c
// where should the mouse go next?
#include <stdbool.h>
#include "walls.h"
#include "decide.h"
#include "flood.h"
#include "direction.h"

// all functions should return a turn value
// L_TURN R_TURN U_TURN or NO_TURN
int r_wall(void) {
    // decide while getting walls
    if (right_wall() == false) return R_TURN;
    else if (front_wall() == false) return NO_TURN;
    else if (left_wall() == false) return L_TURN;
    else return U_TURN;
}

int l_wall(void) {
    // decide while getting walls
    if (left_wall() == false) return L_TURN;
    else if (front_wall() == false) return NO_TURN;
    else if (right_wall() == false) return R_TURN;
    else return U_TURN;
}

int flood(Maze * maze, Mouse * mouse, int x, int y) {
    // flood maze
    flood_maze(maze, x, y);
    // get turn
    return flood_turn(maze, mouse, N);
}

