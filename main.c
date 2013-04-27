#include <p33FJ128MC802.h>
#include "config.h"
#include "main.h"
#include "solve.h"

/* End Interrupt Definitions */
int main(void)
{
	// initialize the mouse
	init_all();

	// solve the maze
	while(1) solve();
}

