#ifndef MAZE_H
#define MAZE_H
#include <stdbool.h>
#include "cell.h"

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
#endif
