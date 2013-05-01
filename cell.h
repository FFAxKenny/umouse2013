#ifndef CELL_H
#define CELL_H
#include <stdbool.h>

typedef struct{
    // walls
    bool s_wall;    // south wall
    bool w_wall;    // west wall

    // cell value
    int val;

    // position
    int x;
    int y;
} Cell;

// prototypes
void init_cell(Cell * cell, int x, int y);

void set_s_wall(Cell * cell);
void del_s_wall(Cell * cell);
bool has_s_wall(Cell * cell);

void set_w_wall(Cell * cell);
void del_w_wall(Cell * cell);
bool has_w_wall(Cell * cell); 

void set_val(Cell * cell, int val);
int  get_val(Cell * cell);

void set_pos(Cell * cell, int x, int y);
int get_x(Cell * cell);
int get_y(Cell * cell);
#endif

