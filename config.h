// contains macros and function prototypes
// for configuration and initialization

// Values for right prescaler
#define PR1_MAX 0x30FF

// Values for left prescaler
#define PR2_MAX 0x30FF

// initialize the mouse
void init_all(void);

// configure interrupts
void config_interrupts(void);

// configure clock
void init_clock(void);

// configure io
void config_io(void);
