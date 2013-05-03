// cell.c
// functions for cells
#include <stdbool.h>
#include <stdlib.h>
#include "cell.h"

// initialize cell
void init_cell(Cell * cell, int x, int y) {
    if(cell != NULL) {
        del_s_wall(cell);   // set south wall to false
        del_w_wall(cell);   // set west wall to false
        set_pos(cell,x,y);  // set the position of the cell
    }
}

// functions on south wall
void set_s_wall(Cell * cell) {
    if(cell != NULL) {
        cell->s_wall = true;
    }
}
void del_s_wall(Cell * cell) {
    if(cell != NULL) {
        cell->s_wall = false;
    }
}
bool has_s_wall(Cell * cell) {
    if(cell != NULL) {
        return cell->s_wall;
    }
    else return true;
}

// functions on west wall
void set_w_wall(Cell * cell) {
    if(cell != NULL) {
        cell->w_wall = true;
    }
}
void del_w_wall(Cell * cell) {
    if(cell != NULL) {
        cell->w_wall = false;
    }
}
bool has_w_wall(Cell * cell) {
    if(cell != NULL) {
        return cell->w_wall;
    }
    else return true;
}

// functions on cell value
void set_val(Cell * cell, int val) {
    if(cell != NULL) {
        cell->val = val;
    }
}
int  get_val(Cell * cell) {
    if(cell != NULL) {
        return cell->val;
    }
    else return INF_CELL;
}

// functions on cell position
void set_pos(Cell * cell, int x, int y) {
    if(cell != NULL) {
        cell->x = x;
        cell->y = y;
    }
}
int get_x(Cell * cell) {
    if(cell != NULL) {
        return cell->x;
    }
    else return NOX_CELL;
}
int get_y(Cell * cell) {
    if(cell != NULL) {
        return cell->y;
    }
    else return NOY_CELL;
}

