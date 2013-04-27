#ifndef MOVE_H
#define MOVE_H

// macros and prototypes for moving the mouse

// MID = perfect distance
// DELTA = tolerance
#define BL_MID		2500
#define BL_DELTA	3


#define BR_MID
#define BR_DELTA
#define TLF_MID
#define TLF_DELTA
#define TRF_MID
#define TRF_DELTA

// Correct off front wall
void correct(void);

// Turn with direction from decide.c
void turn(int direction);

// Go forward 1 cell
void track(void);
#endif
