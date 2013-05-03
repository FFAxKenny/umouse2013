#ifndef TREMAUX_H
#define TREMAUX_H
#include "maze.h"
#include "mouse.h"

void tremaux_fill(Maze * maze);

// increment cell value each time entering
void tremaux_increment(Maze * maze, Mouse * mouse);

int tremaux_decide(Maze * maze, Mouse * mouse);

#endif
