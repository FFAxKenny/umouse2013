// contains macros and function prototypes
// for configuration and initialization

// Values for right prescaler
#define PR1_MAP		0x7000	// Max prescaler for tracking
#define PR1_TRACK	0x0700	// CURRENT_MAX-PR1_TRACK = MAX_GAIN
#define PR1_CORRECT	2		// Incremental gain
#define PR1_INIT	0x8000	// To prevent inital drift

// Values for left prescaler
#define PR2_MAP 	0x7000	// Max prescaler for tracking
#define PR2_TRACK	0x0700	// CURRENT_MAX-PR2_TRACK = MAX_GAIN
#define PR2_CORRECT	2		// Incremental gain
#define PR2_INIT	0x8000	// To prevent inital drift

// initialize the mouse
void init_all(void);

// initialize global variables
void init_globals(void);

// configure interrupts
void config_interrupts(void);

// configure clock
void init_clock(void);

// configure io
void config_io(void);
