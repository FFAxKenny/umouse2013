#include "tremaux.h"
#include "maze.h"
#include "mouse.h"
#include "decide.h"

void tremaux_fill(Maze * maze) {
    int x, y;

    // initialize the whole maze
    for(x = 0 ; x <=15 ; x++) {
        for(y = 0 ; y <= 15 ; y++) {
            set_c_val(maze,x,y,0);
        }
    }
    // set first cell as 1
    set_c_val(maze,0,0,1);
}

// increment cell value 
void tremaux_increment(Maze * maze, Mouse * mouse) {
    int x = mouse_x(mouse),
        y = mouse_y(mouse),
        c_dir = mouse_c_dir(mouse);

    if(get_c_val(maze, x, y) == 1 && get_back_val(maze, mouse) >= 2);
    else if (has_r_wall(maze, x, y, c_dir) &&
            has_f_wall(maze, x, y, c_dir) && 
            has_l_wall(maze, x, y, c_dir)) {
        set_c_val(maze,x,y,100);
    }
    else set_c_val(maze, x, y, get_c_val(maze, x, y)+1);
}

// increment cell value each time entering
int tremaux_decide(Maze * maze, Mouse * moose) {
    int x = mouse_x(moose),
        y = mouse_y(moose),
        x_quad = (x >= 8),
        y_quad = (y >= 8),
        c_dir = mouse_c_dir(moose);

    int low_val = INF_CELL,
        new_dir = 0,
        temp_dir,
        temp_val,
        i;

    int dir_arry[4] = {
        c_dir,
        ((c_dir+5)-2*(!x_quad*(c_dir==0)+!y_quad*(c_dir==1)+x_quad*(c_dir==2)+y_quad*(c_dir==3)))%4,
        ((c_dir+3)-2*(!x_quad*(c_dir==0)+!y_quad*(c_dir==1)+x_quad*(c_dir==2)+y_quad*(c_dir==3)))%4,
        (c_dir + 2)%4
    };

    for(i = 0 ; i < 4 ; i++) {
        temp_dir = dir_arry[i];
        if(has_wall_dir(maze,x,y,temp_dir) == false) {
            temp_val = get_val_dir(maze,x,y,temp_dir);
            if(temp_val < low_val) {
                low_val = temp_val;
                new_dir = temp_dir;
            }
        }
    }

    // return result
    switch((new_dir - c_dir + 4) % 4) { // switch on delta dir
        case 0: 
            return NO_TURN;
            break;
        case 1:
            return L_TURN;
            break;
        case 2:
            return U_TURN;
            break;
        case 3:
            return R_TURN;
            break;
        default:
            return NO_TURN;
            break;
    }
}

int tremaux_return(Maze * maze, Mouse * mouse) {
    
}


