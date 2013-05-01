// floodfill
#include "maze.h"
#include "queue.h"

// fill for solving
void init_fill(Maze * maze){
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
    for(x = 0 ; x <= 15 ; x++) {
        for(y = 0 ; y <= 15 ; y++) {
            set_c_val(maze,x,y,(x+y));
        }
    }
}

// flood maze; starting with start_x and start_y
void flood_maze(int start_x, int start_y) {
    Queue queue;

    init_queue(&queue);


}

