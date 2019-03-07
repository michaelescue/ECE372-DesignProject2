// ECE 372 Project 2
// Utilizes I2C1 to communicate with display board.

// Define Indirect Addressing Macro for Registers
#define HWREG(x) (*((volatile unsigned int *)(x)))

// Variables
int current_state = 1;
int x;
volatile unsigned int USR_STACK[100];
volatile unsigned int INT_STACK[100];

int main(void){
// Inline Assembly Initialization.
	asm("LDR R13, =USR_STACK");
	//LED INIT
	HWREG(CLKWKUPS + 0xAC) = 0x2;				//GPIO1 initialization code
	HWREG(GPIO1BA + GPIO_CLEAR_DATA_OUT) = LIGHT_BITS;		//Set initial GPIO values
	HWREG(GPIO1BA + 0x134) &= 0xFE1FFFFF;					// set output enable
    return 1;
}
