// cell.c
// functions for cells
#include <stdbool.h>
#include "cell.h"

// initialize cell
void init_cell(Cell * cell) {
    del_s_wall(cell);   // set south wall to false
    del_w_wall(cell);   // set west wall to false
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
