#include <avr/io.h>
#include <util/delay.h>
#ifndef PIN_DEF_H_
#define PIN_DEF_H_

// PORT C
#define PIN_C0	0
#define PIN_C1	1
#define PIN_C2	2
#define PIN_C3	3
#define PIN_C4	4
#define PIN_C5	5
#define PIN_C6  6
#define PIN_C7	7

// PORT D
#define PIN_D0	8
#define PIN_D1	9
#define PIN_D2	10
#define PIN_D3	11
#define PIN_D4	12
#define PIN_D5	13
#define PIN_D6	14
#define PIN_D7  15

// PORT B
#define PIN_B0	16
#define PIN_B1	17
#define PIN_B2	18
#define PIN_B3	19
#define PIN_B4	20
#define PIN_B5	21

#define PIN_HIGH	1
#define PIN_LOW		0
#define PIN_ENABLE	1
#define PIN_UNABLE	0

void setPinMode(unsigned short pinNum, unsigned short pinMode);
void setPinHigh(unsigned short pinNum);
void setPinLow(unsigned short pinNum);

#endif /* PIN_DEF_H_ */
