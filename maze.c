// maze.c
// functions for maze
#include <stdbool.h>
#include "maze.h"
#include "direction.h"

// initalize maze
void init_maze(Maze * maze) {
    int x;
    int y;

    // init all cells
    for (x = 0 ; x < 17 ; x++) {
        for (y = 0 ; y < 17 ; y++) {
            init_cell(&(maze->cells[x][y]));
        }
    }

    // add west walls for x = 0, 16
    x = 0;
    for (y = 0 ; y < 17 ; y++) {
        set_w_wall(&(maze->cells[x][y]));
    }
    x = 16;
    for (y = 0 ; y < 17 ; y++) {
        set_w_wall(&(maze->cells[x][y]));
    }

    // add south walls for y = 0, 16
    y = 0;
    for (x = 0 ; x < 17 ; x++) {
        set_s_wall(&(maze->cells[x][y]));
    }
    y = 16;
    for (x = 0 ; x < 17 ; x++) {
        set_s_wall(&(maze->cells[x][y]));
    }
}

// functions for front wall
void set_f_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; set south of y+1
       case N:
            set_s_wall(&(maze->cells[x][y+1]));
            break;
       // front is south; set south of x,y
       case S: 
            set_s_wall(&(maze->cells[x][y]));
            break;
       // front is east; set west of x+1
       case E: 
            set_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is west; set west of x,y
       case W:
            set_w_wall(&(maze->cells[x][y]));
            break;
       default: break;
    }
}
void del_f_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; delete south of y+1
       case N:
            del_s_wall(&(maze->cells[x][y+1]));
            break;
       // front is south; delete south of x,y
       case S: 
            del_s_wall(&(maze->cells[x][y]));
            break;
       // front is east; delete west of x+1
       case E: 
            del_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is west; delete west of x,y
       case W:
            del_w_wall(&(maze->cells[x][y]));
            break;
       default: break;
    }
}
bool has_f_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; get south of y+1
       case N:
            return has_s_wall(&(maze->cells[x][y+1]));
            break;
       // front is south; get south of x,y
       case S: 
            return has_s_wall(&(maze->cells[x][y]));
            break;
       // front is east; get west of x+1
       case E: 
            return has_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is west; get west of x,y
       case W:
            return has_w_wall(&(maze->cells[x][y]));
            break;
       default: return false;
    }
}

// functions for left wall
void set_l_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; set west of x,y
       case N:
            set_w_wall(&(maze->cells[x][y]));
            break;
       // front is south; set west of x+1
       case S: 
            set_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is east; set south of y+1
       case E: 
            set_s_wall(&(maze->cells[x][y+1]));
            break;
       // front is west; set south of x,y
       case W:
            set_s_wall(&(maze->cells[x][y]));
            break;
       default: break;
    }
}
void del_l_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; del west of x,y
       case N:
            del_w_wall(&(maze->cells[x][y]));
            break;
       // front is south; del west of x+1
       case S: 
            del_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is east; del south of y+1
       case E: 
            del_s_wall(&(maze->cells[x][y+1]));
            break;
       // front is west; del south of x,y
       case W:
            del_s_wall(&(maze->cells[x][y]));
            break;
       default: break;
    }
}
bool has_l_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; get west of x,y
       case N:
            return has_w_wall(&(maze->cells[x][y]));
            break;
       // front is south; get west of x+1
       case S: 
            return has_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is east; get south of y+1
       case E: 
            return has_s_wall(&(maze->cells[x][y+1]));
            break;
       // front is west; get south of x,y
       case W:
            return has_s_wall(&(maze->cells[x][y]));
            break;
       default: return false;
    }
}

// functions for right wall
void set_r_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; set west of x+1,y
       case N:
            set_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is south; set west of x,y
       case S: 
            set_w_wall(&(maze->cells[x][y]));
            break;
       // front is east; set south of x,y
       case E: 
            set_s_wall(&(maze->cells[x][y]));
            break;
       // front is west; set south of x,y+1
       case W:
            set_s_wall(&(maze->cells[x][y+1]));
            break;
       default: break;
    }
}
void del_r_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; del west of x+1,y
       case N:
            del_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is south; del west of x,y
       case S: 
            del_w_wall(&(maze->cells[x][y]));
            break;
       // front is east; del south of x,y
       case E: 
            del_s_wall(&(maze->cells[x][y]));
            break;
       // front is west; del south of x,y+1
       case W:
            del_s_wall(&(maze->cells[x][y+1]));
            break;
       default: break;
    }
}
bool has_r_wall(Maze * maze, int x, int y, int c_dir) {
    switch(c_dir) {
       // front is north; get west of x+1,y
       case N:
            return has_w_wall(&(maze->cells[x+1][y]));
            break;
       // front is south; get west of x,y
       case S: 
            return has_w_wall(&(maze->cells[x][y]));
            break;
       // front is east; get south of x,y
       case E: 
            return has_s_wall(&(maze->cells[x][y]));
            break;
       // front is west; get south of x,y+1
       case W:
            return has_s_wall(&(maze->cells[x][y+1]));
            break;
       default: return false;
    }
}

// functions for cell value
void set_c_val(Maze * maze, int x, int y, int val) {
    set_val(&(maze->cells[x][y]),val);
}
int get_c_val(Maze * maze, int x, int y) {
    return get_val(&(maze->cells[x][y]));
}
