#ifndef MOTORS_H
#define MOTORS_H

//Direction macros
//Tell the mouse which 
//direction to go
#define FORWARD  1
#define RIGHT    2
#define BACKWARD 3
#define LEFT 	 4
#define STOP 	 5
#define TURN     6

// correction macros
#define R_FORE	7
#define R_BACK	8
#define L_FORE	9
#define L_BACK	10

// Values to AND for left and right sequence
#define LS_AND	0b1100001111111111
#define RS_AND	0b1111110000111111

// Values to ADD for the left sequence
#define LS_0	0b0000010000000000
#define LS_1	0b0000100000000000
#define LS_2	0b0001000000000000
#define LS_3	0b0010000000000000

// Values to ADD for the right sequence
#define RS_0	0b0000001000000000
#define RS_1	0b0000000100000000
#define RS_2	0b0000000010000000
#define RS_3	0b0000000001000000

// step count for turns
#define R_STEP 83
#define L_STEP 83
#define T_STEP 167
#define F_STEP 203
#endif
