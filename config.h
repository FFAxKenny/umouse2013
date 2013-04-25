// contains macros and function prototypes
// for configuration and initialization

// Values for right prescaler
#define PR1_MAX		0x30FF
#define PR1_INIT	0x8000

// Values for left prescaler
#define PR2_MAX 	0x30FF
#define PR2_INIT	0x8000

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
