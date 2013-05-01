#ifndef CELL_H
#define CELL_H
#include <stdbool.h>

#define C_INIT 0

typedef struct{
    // walls
    bool s_wall;    // south wall
    bool w_wall;    // west wall

    // cell value
    int val;
} Cell;

// prototypes
void init_cell(Cell * cell);

void set_s_wall(Cell * cell);
void del_s_wall(Cell * cell);
bool has_s_wall(Cell * cell);

void set_w_wall(Cell * cell);
void del_w_wall(Cell * cell);
bool has_w_wall(Cell * cell); 

void set_val(Cell * cell, int val);
int  get_val(Cell * cell);
#endif
