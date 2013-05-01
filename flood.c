// floodfill
#include <stdbool.h>
#include "maze.h"
#include "queue.h"
#include "cell.h"
#include "direction.h"

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
    Cell * cur_cell;
    Queue queue;
    Queue * q = &queue;
    init_queue(q);

    // get the first cell
    q_push(q, get_cell(maze, start_x, start_y));

    // while queue is not empty
    while(is_empty(q) != true) {
        // get cell
        cur_cell = q_pop(q);

        // get cell value
        old_val = get_val(cur_cell);
        // get position
        x = get_x(cur_cell);
        y = get_y(cur_cell);

        // initialize new cell value
        new_val = old_val;

        // check accessible neighbors
        for (dir = N ; dir < E ; dir++) {
            if(has_wall_dir(maze,x,y,dir) == false) {
                temp_val = get_val_dir(maze,x,y,dir);
                // if accessed value is less than new value
                // new value = accessed + 1
                if(temp_val < new_val) new_val = temp_val + 1;
            }
        }

        // if new value is different
        // update value and add all accessible neighbors to queue
        // otherwise, do nothing
        if(old_val != new_val) {
            set_val(cur_cell, new_val);
            for (dir = N ; dir < E ; dir++) {
                if(has_wall_dir(maze,x,y,dir) == false) {
                    q_push(q, get_cell_dir(maze,x,y,dir));
                }
            }
        }
    }
}

