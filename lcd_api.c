#include "lcd_api.h"
#include "pin_def.h"

void createInstructions(LCDSettings* settings)
{

	//
	// These two variables will be sent by the ATMEL328P...
	// g_displaySettings will configure how the display should look.
	// g_functionSettings will control the instruction type, line amount, and dot type
	//

	//00001DCB
	g_displaySettings = (8 | ((settings->cursorSet << 1) | (settings->blinkSet << 0)) );

	//001DNFxx
	//	 L
	g_functionSettings = (32 | ((settings->insType << 4)  | (settings->lineAmt << 3)) | (settings->dotDimension << 2));
}

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
)
{
	_D0 = D0;
	_D1 = D1;
	_D2 = D2;
	_D3 = D3;
	_D4 = D4;
	_D5 = D5;
	_D6 = D6;
	_D7 = D7;
	_RS = RS;
	_RW = RW;
	_E  = E;
	if (D0 != IGNORE){
		_D0_SHIFT  = D0 % 8;
		setPinMode(D0, PIN_ENABLE);
	}
	else
		_D0_SHIFT = 255;

	if (D1 != IGNORE){
		_D1_SHIFT  = D1 % 8;
		setPinMode(D1, PIN_ENABLE);
	}
	else
		_D1_SHIFT = 255;

	if (D2 != IGNORE)
	{
		_D2_SHIFT  = D2 % 8;
		setPinMode(D2, PIN_ENABLE);
	}
	else
		_D2_SHIFT = 255;

	if (D3 != IGNORE)
	{
		_D3_SHIFT  = D3 % 8;
		setPinMode(D3, PIN_ENABLE);
	}
	else
		_D3_SHIFT = 255;

	if (D4 != IGNORE)
	{
		_D4_SHIFT  = D4 % 8;
		setPinMode(D4, PIN_ENABLE);
	}
	else
		_D4_SHIFT = 255;

	if (D5 != IGNORE)
	{
		_D5_SHIFT  = D5 % 8;
		setPinMode(D5, PIN_ENABLE);
	}
	else
		_D5_SHIFT = 255;

	if (D6 != IGNORE)
	{
		_D6_SHIFT  = D6 % 8;
		setPinMode(D6, PIN_ENABLE);
	}
	else
		_D6_SHIFT = 255;

	if (D7 != IGNORE)
	{
		_D7_SHIFT  = D7 % 8;
		setPinMode(D7, PIN_ENABLE);
	}
	else
		_D7_SHIFT = 255;

	if (RS != IGNORE)
	{
		_RS_SHIFT  = RS % 8;
		setPinMode(RS, PIN_ENABLE);
	}
	else
		_RS_SHIFT = 255;

	if (RW != IGNORE)
	{
		_RW_SHIFT  = RW % 8;
		setPinMode(RW, PIN_ENABLE);
	}
	else
		_RW_SHIFT = 255;

	if (E != IGNORE)
	{
		_E_SHIFT = E % 8;
		setPinMode(E, PIN_ENABLE);
	}
	else
		_E_SHIFT = 255;


}

void _insMode()
{
	setPinLow(_E);
	setPinLow(_RS);
}

void _send4bits(unsigned char theBits)
{
	setPinLow(_D7);
	if (theBits & (1 << _D7_SHIFT)) setPinHigh(_D7);

	setPinLow(_D6);
	if (theBits & (1 << _D6_SHIFT)) setPinHigh(_D6);

	setPinLow(_D5);
	if (theBits & (1 << _D5_SHIFT)) setPinHigh(_D5);

	setPinLow(_D4);
	if (theBits & (1 << _D4_SHIFT)) setPinHigh(_D4);

	_enablePulse();
}

void _enablePulse()
{
	setPinHigh(_E);
	_delay_ms(101);
	setPinLow(_E);
	_delay_ms(101);
}
