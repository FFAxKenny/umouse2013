#include "decide.h"
#include "move.h"

// solve the maze
void solve(void) {
    while (1){
		// get direction and turn
		turn(r_wall());

		// move forward 1 cell
		track();
	}
}
