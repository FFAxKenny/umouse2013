#include "decide.h"
#include "move.h"
#include "walls.h"
#include "solve.h"
#include "main.h"

// solve the maze
void solve(void) {
	if(ALG == R_WALL) {	//right wall hug
	    while (1){
			// move forward 1 cell
			track();

			// get direction and turn
			turn(r_wall());
		}
	}
//	else if(ALG == L_WALL) {	//left wall hug
//	}
//	else if(ALG == TREMAUX) {	//tremaux algorithm
//	}
//	else if(ALG == FLOOD) {	//floodfill
//		
//	}
//	else {}
}
