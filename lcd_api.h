#ifndef LCD_API_H_
#define LCD_API_H_

#include <avr/io.h>
#include <util/delay.h>

////////////
// MACROS //
////////////


#define FUNCTION_SET 		0b00110000
#define FUNCTION_SET_4_BIT 	0b00101000
#define DISPLAY_ON  		0b00001111
#define DISPLAY_ON_C  		0b00001110
#define DISPLAY_ON_NC  		0b00001100
#define DISPLAY_OFF 		0b00001000
#define CLEAR_DISPLAY 		0b00000001

#define IGNORE 				255

volatile unsigned char _D0;
volatile unsigned char _D1;
volatile unsigned char _D2;
volatile unsigned char _D3;
volatile unsigned char _D4;
volatile unsigned char _D5;
volatile unsigned char _D6;
volatile unsigned char _D7;

volatile unsigned char _RS;
volatile unsigned char _RW;
volatile unsigned char _E;

unsigned char _D0_DDR;
unsigned char _D1_DDR;
unsigned char _D2_DDR;
unsigned char _D3_DDR;
unsigned char _D4_DDR;
unsigned char _D5_DDR;
unsigned char _D6_DDR;
unsigned char _D7_DDR;

unsigned char _RS_DDR;
unsigned char _RW_DDR;
unsigned char _E_DDR;

unsigned char _D0_SHIFT;
unsigned char _D1_SHIFT;
unsigned char _D2_SHIFT;
unsigned char _D3_SHIFT;
unsigned char _D4_SHIFT;
unsigned char _D5_SHIFT;
unsigned char _D6_SHIFT;
unsigned char _D7_SHIFT;

unsigned char _RS_SHIFT;
unsigned char _RW_SHIFT;
unsigned char _E_SHIFT;

#define D0_HIGH		(1 << _D0_SHIFT)
#define D0_LOW      ~(1 << _D0_SHIFT)

#define D1_HIGH		(1 << _D1_SHIFT)
#define D1_LOW	    ~(1 << _D1_SHIFT)

#define D2_HIGH		(1 << _D2_SHIFT)
#define D2_LOW	    ~(1 << _D2_SHIFT)

#define D3_HIGH		(1 << _D3_SHIFT)
#define D3_LOW		~(1 << _D3_SHIFT)

#define D4_HIGH		(1 << _D4_SHIFT)
#define D4_LOW		~(1 << _D4_SHIFT)

#define D5_HIGH		(1 << _D5_SHIFT)
#define D5_LOW		~(1 << _D5_SHIFT)

#define D6_HIGH		(1 << _D6_SHIFT)
#define D6_LOW		~(1 << _D6_SHIFT)

#define D7_HIGH		(1 << _D7_SHIFT)
#define D7_LOW		~(1 << _D7_SHIFT)

#define RS_HIGH		(1 << _RS_SHIFT)
#define RS_LOW		~(1 << _RS_SHIFT)

#define RW_HIGH		(1 << _RW_SHIFT)
#define RW_LOW		~(1 << _RW_SHIFT)

#define E_HIGH		(1 << _E_SHIFT)
#define E_LOW	    ~(1 << _E_SHIFT)

#define LCD_PORTB  PORTB
#define LCD_DDRB   DDRB

#define LCD_PORTC  PORTC
#define LCD_DDRC   DDRC

#define LCD_PORTD  PORTD
#define LCD_DDRD   DDRD


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
void configurePin
(
	unsigned char D0,
	unsigned char D1,
	unsigned char D2,
	unsigned char D3,
	unsigned char D4,
	unsigned char D5,
	unsigned char D6,
	unsigned char D7,
	unsigned char RS,
	unsigned char RW,
	unsigned char E
);

void writeChar();
void sendIns();
void _send4bits(unsigned char theBits);
void _enablePulse();
void _insMode();
void _charMode();

#endif
