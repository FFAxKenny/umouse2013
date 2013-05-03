#ifndef FLOOD_H
#define FLOOD_H
#include "maze.h"
#include "mouse.h"

// fill for solving
void init_fill(Maze * maze);
// fill for return to start
void back_fill(Maze * maze);

// flood maze; starting with start_x and start_y
void flood_maze(Maze * maze, int start_x, int start_y);

// decide where to turn given mouse
int flood_turn(Maze * maze, Mouse * mouse);
#endif

