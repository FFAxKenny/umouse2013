// cell.c
// functions for cells
#include <stdbool.h>
#include "cell.h"

// initialize cell
void init_cell(Cell * cell, int x, int y) {
    del_s_wall(cell);   // set south wall to false
    del_w_wall(cell);   // set west wall to false
    set_pos(cell,x,y);  // set the position of the cell
}

// functions on south wall
void set_s_wall(Cell * cell) {
    cell->s_wall = true;
}
void del_s_wall(Cell * cell) {
    cell->s_wall = false;
}
bool has_s_wall(Cell * cell) {
    return cell->s_wall;
}

// functions on west wall
void set_w_wall(Cell * cell) {
    cell->w_wall = true;
}
void del_w_wall(Cell * cell) {
    cell->w_wall = false;
}
bool has_w_wall(Cell * cell) {
    return cell->w_wall;
}

// functions on cell value
void set_val(Cell * cell, int val) {
    cell->val = val;
}
int  get_val(Cell * cell) {
    return cell->val;
}

// functions on cell position
void set_pos(Cell * cell, int x, int y) {
    cell->x = x;
    cell->y = y;
}
int get_x(Cell * cell) {
    return cell->x;
}
int get_y(Cell * cell) {
    return cell->y;
}

