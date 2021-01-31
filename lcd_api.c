#include "lcd_api.h"

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

void fourbitPinmap()
{

}
