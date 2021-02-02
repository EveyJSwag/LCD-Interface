#include "pin_def.h"
void setPinMode(unsigned short pinNum, unsigned short pinMode)
{
	if (pinNum < PIN_D0) {DDRC |= (pinMode << pinNum % 8);}

	if (pinNum > PIN_C7 && pinNum < PIN_B0){DDRD |= (pinMode << pinNum % 8);}

	if (pinNum > PIN_D7 && pinNum < (PIN_B5+1)){DDRB |= (pinMode << pinNum % 8);}

}
void setPinHigh(unsigned short pinNum)
{
	if (pinNum < PIN_D0) {PORTC |= (PIN_HIGH << pinNum % 8);}

	if (pinNum > PIN_C7 && pinNum < PIN_B0){PORTD |= (PIN_HIGH << pinNum % 8);}

	if (pinNum > PIN_D7 && pinNum < (PIN_B5+1)){PORTB |= (PIN_HIGH << pinNum % 8);}
}
void setPinLow(unsigned short pinNum)
{
	if (pinNum < PIN_D0) {PORTC &= ~(PIN_HIGH << pinNum % 8);}

	if (pinNum > PIN_C7 && pinNum < PIN_B0){PORTD &= ~(PIN_HIGH << pinNum % 8);}

	if (pinNum > PIN_D7 && pinNum < (PIN_B5+1)){PORTB &= ~(PIN_HIGH << pinNum % 8);}
}
