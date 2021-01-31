#ifndef LCD_API_H_
#define LCD_API_H_


#define FUNCTION_SET 0b00110000
#define FUNCTION_SET_4_BIT 0b00101000
#define DISPLAY_ON  0b00001111
#define DISPLAY_ON_C  0b00001110
#define DISPLAY_ON_NC  0b00001100
#define DISPLAY_OFF 0b00001000
#define CLEAR_DISPLAY 0b00000001

unsigned char _D0;
unsigned char _D1;
unsigned char _D2;
unsigned char _D3;
unsigned char _D4;
unsigned char _D5;
unsigned char _D6;
unsigned char _D7;

unsigned char _RS;
unsigned char _RW;
unsigned char _E;

typedef struct LCDSettings
{
	// 0: 4 bit
	// 1: 8 bit
	unsigned char insType;

	// 0: 1 line
	// 1: 2 lines
	unsigned char lineAmt;
	// 0: 5x7  dots
	// 1: 5x10 dots
	unsigned char dotDimension;

	// 0: cursor off
	// 1: cursor on
	unsigned char cursorSet;
	// 0: blink off
	// 1: blink on
	unsigned char blinkSet;
} LCDSettings;

unsigned char g_displaySettings;
unsigned char g_functionSettings;

void createInstructions(LCDSettings* settings);

void writeChar();
void sendIns();
void _enablePulse();
void fourbitPinmap();

#endif
