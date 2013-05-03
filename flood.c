// floodfill
#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"
#include "queue.h"
#include "cell.h"
#include "direction.h"
#include "decide.h"
#include "delay_T4.h"

// fill for solving
void init_fill(Maze * maze){
	int x, y;

    // initialize left half
    for(x = 0 ; x <=7 ; x++) {
        for(y = 0 ; y <= 7 ; y++) {
            set_c_val(maze,x,y,((7-x)+(7-y)));
        }
        for(y = 8 ; y <= 15 ; y++) {
            set_c_val(maze,x,y,((7-x)+(y-8)));
        }
    }
    // initialize right half
    for(x = 8 ; x <=15 ; x++) {
        for(y = 0 ; y <= 7 ; y++) {
            set_c_val(maze,x,y,((x-8)+(7-y)));
        }
        for(y = 8 ; y <= 15 ; y++) {
            set_c_val(maze,x,y,((x-8)+(y-8)));
        }
    }
	// initialize the rest
	x = 16;
	for(y = 0 ; y < 17 ; y++) {
	    set_c_val(maze,x,y,INF_CELL);
	}
	y = 16;
	for(x = 0 ; x < 17 ; x++) {
	    set_c_val(maze,x,y,INF_CELL);
	}
}
// fill for return to start
void back_fill(Maze * maze){
	int x, y;

    for(x = 0 ; x <= 15 ; x++) {
        for(y = 0 ; y <= 15 ; y++) {
            set_c_val(maze,x,y,(x+y));
        }
    }
}

// flood maze; starting with start_x and start_y
void flood_maze(Maze * maze, int start_x, int start_y) {
	int old_val;
    int new_val;
    int temp_val;
    int dir;
    int x;
    int y;
	int iterations = 0;
    Cell * cur_cell;
    Queue queue;
    Queue * q = &queue;
    init_queue(q);

	// init fill
//	init_fill(maze);

    // get the first cell
    q_push(q, get_cell(maze, start_x, start_y));

    // while queue is not empty
    while(is_empty(q) != true) {
		iterations++;

        // get cell
        cur_cell = q_pop(q);

		// don't process a null cell
		if (cur_cell != NULL) {
	        // get cell value
	        old_val = get_val(cur_cell);
    	    // get position
    	    x = get_x(cur_cell);
			y = get_y(cur_cell);

			if(x >= 0 && x <= 15 && y >= 0 && y <= 15) {
		        // initialize new cell value
		        new_val = old_val;

		        // check accessible neighbors
		        for (dir = 0 ; dir <= 3 ; dir++) {
		            if(has_wall_dir(maze,x,y,dir) == false) {
		                temp_val = get_val_dir(maze,x,y,dir);
		                // if accessed value is less than new value
		                // new value = accessed + 1
		                if(temp_val <= new_val) new_val = temp_val + 1;
		            }
		        }
	
		        // if new value is different
		        // update value and add all accessible neighbors to queue
		        // otherwise, do nothing
		        if(old_val != new_val) {
		            set_val(cur_cell, new_val);
		            for (dir = 0 ; dir <= 3 ; dir++) {
		                if(has_wall_dir(maze,x,y,dir) == false) {
		                    q_push(q, get_cell_dir(maze,x,y,dir));
		                }
					}
	            }
	        }
		}
    }
}

// decide where to turn given moose
int flood_turn(Maze * maze, Mouse * moose) {
    int x = mouse_x(moose),
		y = mouse_y(moose),
		x_quad = (x >= 8),
        y_quad = (y >= 8),
        c_dir = mouse_c_dir(moose);

    int low_val = INF_CELL,
		new_dir = 3,
		temp_dir,
		temp_val,
		i;

	int dir_arry[4] = {
		c_dir,
		((c_dir+5)-2*(!x_quad*(c_dir==0)+!y_quad*(c_dir==1)+x_quad*(c_dir==2)+y_quad*(c_dir==3)))%4,
		((c_dir+3)-2*(!x_quad*(c_dir==0)+!y_quad*(c_dir==1)+x_quad*(c_dir==2)+y_quad*(c_dir==3)))%4,
		(c_dir + 2)%4
	};

	for(i = 0 ; i < 4 ; i++) {
		temp_dir = dir_arry[i];
		if(has_wall_dir(maze,x,y,temp_dir) == false) {
			temp_val = get_val_dir(maze,x,y,temp_dir);
			if(temp_val < low_val) {
				low_val = temp_val;
				new_dir = temp_dir;
			}
		}
	}

    // return result
    switch((new_dir - c_dir + 4) % 4) { // switch on delta dir
        case 0: 
            return NO_TURN;
            break;
        case 1:
            return L_TURN;
            break;
        case 2:
            return U_TURN;
            break;
        case 3:
            return R_TURN;
            break;
        default:
            return NO_TURN;
            break;
    }
}
