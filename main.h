#ifndef MAIN_H
#define MAIN_H
#include "maze.h"
#include "mouse.h"
// Declare global variables

extern int L_IND,	// Left index
	R_IND,			// Right index
	DIR,			// Direction of movement
    DELAY_COUNT,	// Delay count for delay interrupt
	MAX_DELAY,		// Max delay for delay interrupt
    RDY,			// Ready bit for delay interrupt
    ST_COUNT,		// Step count
	ALG;			// Solving algorithm

extern unsigned int L_SEQ[4];	// Left sequence

extern unsigned int R_SEQ[4];	// Right sequence

extern Maze MAZE;   // maze

extern Mouse MOUSE; // mouse
#endif
