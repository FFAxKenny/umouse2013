#include <p33FJ128MC802.h>
#include <stdbool.h>
#include "decide.h"
#include "move.h"
#include "walls.h"
#include "solve.h"
#include "main.h"
#include "mouse.h"
#include "maze.h"
#include "flood.h"
#include "direction.h"

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
	else if(ALG == L_WALL) {	//left wall hug
	    while (1){
			// move forward 1 cell
			track();

			// get direction and turn
			turn(l_wall());
		}
	}
	else if(ALG == TEST) {	//test algorithm
        // solve
        init_fill(maze_p);
		while(1) {
			if (has_wall_dir(maze_p, mouse_x(mouse_p), mouse_y(mouse_p), E) == true) PORTBbits.RB2 = 1;
			else PORTBbits.RB2 = 0;
			if (mouse_c_dir(mouse_p) == N) PORTBbits.RB3 = 1;
			else PORTBbits.RB3 = 0;
            // go forward
			if( get_val_dir(maze_p,mouse_x(mouse_p),mouse_y(mouse_p),mouse_c_dir(mouse_p)) > 8 && get_val_dir(maze_p,mouse_x(mouse_p),mouse_y(mouse_p),mouse_c_dir(mouse_p)) <= 14) {
            	track();
            	go_f(mouse_p);
			}
			else {
				turn(R_TURN);
				go_turn(mouse_p, R_TURN);
			}
            // update maze
            set_walls_mouse(maze_p, mouse_p);
		}
	}
	else if(ALG == FLOOD) {	//floodfill
        while(1) {
            // solve
            init_fill(maze_p);
            while(mouse_x(mouse_p) != 7 || mouse_y(mouse_p) != 7) {
				if (mouse_x(mouse_p) == 0 && mouse_y(mouse_p) == 7) PORTBbits.RB2 = 1;
				else PORTBbits.RB2 = 0;
				if (mouse_c_dir(mouse_p) == N) PORTBbits.RB3 = 1;
				else PORTBbits.RB3 = 0;

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
