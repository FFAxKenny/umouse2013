#include <p33FJ128MC802.h>
#include "config.h"
#include "main.h"
#include "decide.h"
#include "move.h"

/* End Interrupt Definitions */
int main(void)
{
	// initialize the mouse
	init_all();

    while (1){
		// get direction and turn
		turn(r_wall());

		// move forward 1 cell
		track();
	}
}

