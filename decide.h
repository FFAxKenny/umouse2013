#ifndef DECIDE_H
#define DECIDE_H

// protos and macros for decide.c
#define L_TURN  0
#define R_TURN  1
#define U_TURN  2
#define NO_TURN 3

// choose an algorithm
#define R_WALL  0
#define L_WALL  1
#define TREMAUX 3
#define FLOOD   4

int r_wall();
#endif
