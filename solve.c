#include "decide.h"
#include "move.h"
#include "walls.h"
#include "solve.h"
#include "main.h"
#include "mouse.h"
#include "maze.h"
#include "flood.h"

// solve the maze
void solve(void) {
    Mouse mouse;
    Maze  maze;
    Mouse * mouse_p = &mouse;
    Maze * maze_p = &maze;

    init_mouse(mouse_p);
    init_maze(maze_p);

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
	else if(ALG == FLOOD) {	//floodfill
        while(1) {
            // solve
            init_fill(maze_p);
            while(mouse_x(mouse_p) != 7 || mouse_y(mouse_p) != 7) {
                // go forward
                track();
                // update mouse
                go_f(mouse_p);

                // update maze
                set_walls_mouse(maze_p, mouse_p);
                // flood maze
                // get next turn
                // turn
                // update mouse
                go_turn(mouse_p, turn(flood(maze_p, mouse_p, 7, 7)));
            }

            // return to start
            back_fill(maze_p);
            while(mouse_x(mouse_p) != 0 || mouse_y(mouse_p) != 0) {
                // go forward
                track();
                // update mouse
                go_f(mouse_p);

                // update maze
                set_walls_mouse(maze_p, mouse_p);
                // flood maze
                // get next turn
                // turn
                // update mouse
                go_turn(mouse_p, turn(flood(maze_p, mouse_p, 0, 0)));
            }
        }
    }
    //	else {}
}
