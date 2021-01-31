
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd_api.h"

#define FUNCTION_SET 0b00110000
#define FUNCTION_SET_4_BIT 0b00101000
#define DISPLAY_ON  0b00001111
#define DISPLAY_ON_C  0b00001110
#define DISPLAY_ON_NC  0b00001100
#define DISPLAY_OFF 0b00001000
#define CLEAR_DISPLAY 0b00000001

void pin_setup(void);

void power_setup(void);

void send_4_bits(unsigned char ins);

void send_char(unsigned char chr);

void enable_pulse(void);

void send_ins(unsigned char chr);

int main(void)
{
	pin_setup();
	power_setup();

	send_ins(DISPLAY_OFF);
	send_ins(DISPLAY_ON_C);
	send_char('g');
	send_char('l');
	send_char('e');
	send_char('n');
	send_char('n');
	send_char('a');
	//_delay_ms(9000);
	//send_ins(CLEAR_DISPLAY);



	while(1);
	return 0;
}

void pin_setup(void)
{
	_delay_ms(16);
	DDRD |= (1 << 7);
	DDRD |= (1 << 6);
	DDRD |= (1 << 5);
	DDRD |= (1 << 4);

	DDRB |= (1 << 0);
	DDRB |= (1 << 1);

	PORTB &= ~(1 << 0);
	PORTB &= ~(1 << 1);
}

void power_setup(void)
{
	_delay_ms(20);
	PORTB &= ~(1 << 0);
	PORTB &= ~(1 << 1);

	send_4_bits(FUNCTION_SET);
	_delay_ms(5);

	send_4_bits(FUNCTION_SET);
	_delay_ms(5);

	send_4_bits(FUNCTION_SET);
	_delay_ms(5);

	send_4_bits(FUNCTION_SET_4_BIT);
	_delay_ms(5);

	send_ins(FUNCTION_SET_4_BIT);
	_delay_ms(5);
}

void  send_4_bits(unsigned char ins)
{
	PORTD &= ~(1 << 7);
	if (ins & 1 << 7) PORTD |= (1 << 7);

	PORTD &= ~(1 << 6);
	if (ins & 1 << 6) PORTD |= (1 << 6);

	PORTD &= ~(1 << 5);
	if (ins & 1 << 5) PORTD |= (1 << 5);

	PORTD &= ~(1 << 4);
	if (ins & 1 << 4) PORTD |= (1 << 4);

	enable_pulse();
}

void send_char(unsigned char chr)
{
	PORTB |=  (1 << 0);
	PORTB &= ~(1 << 1);
	 send_4_bits(chr);
	_delay_ms(10);
	 send_4_bits(chr << 4);
	_delay_ms(10);
}

void send_ins(unsigned char chr)
{
	PORTB &= ~(1 << 0);
	PORTB &= ~(1 << 1);
	 send_4_bits(chr);
	_delay_ms(10);
	 send_4_bits(chr << 4);
	_delay_ms(10);
}

void enable_pulse(void)
{
	PORTB |=  (1 << 1);
	_delay_ms(101);
	PORTB &= ~(1 << 1);
	_delay_ms(101);
}
