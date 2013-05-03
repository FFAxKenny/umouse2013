#ifndef MAZE_H
#define MAZE_H
#include <stdbool.h>
#include "cell.h"
#include "mouse.h"

typedef struct{
    // Cells
    Cell cells[17][17];
} Maze;

// prototypes
void init_maze(Maze * maze);

void set_f_wall(Maze * maze, int x, int y, int c_dir);
void del_f_wall(Maze * maze, int x, int y, int c_dir);
bool has_f_wall(Maze * maze, int x, int y, int c_dir);

void set_l_wall(Maze * maze, int x, int y, int c_dir);
void del_l_wall(Maze * maze, int x, int y, int c_dir);
bool has_l_wall(Maze * maze, int x, int y, int c_dir);

void set_r_wall(Maze * maze, int x, int y, int c_dir);
void del_r_wall(Maze * maze, int x, int y, int c_dir);
bool has_r_wall(Maze * maze, int x, int y, int c_dir);

void set_c_val(Maze * maze, int x, int y, int val);
int get_c_val(Maze * maze, int x, int y);

// has a wall in c_dir direction
bool has_wall_dir(Maze * maze, int x, int y, int c_dir);
// get a cell at position
Cell * get_cell(Maze * maze, int x, int y);
// get cell in c_dir direction
Cell * get_cell_dir(Maze * maze, int x, int y, int c_dir);
// get value of cell in c_dir direction
int get_val_dir(Maze * maze, int x, int y, int c_dir);

void set_walls_mouse(Maze * maze, Mouse * mouse);

int get_back_val(Maze * maze, Mouse * mouse);
#endif
