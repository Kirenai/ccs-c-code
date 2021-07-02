#include <16f628a.h>
#fuses XT, NOWDT, NOPROTECT, PUT
#use delay(clock=4M)

#byte TRISB = 0x86
#byte PORTB = 0x06

#define M1 0x1F
#define M2 0x0E
#define M3 0x04
#define M4 0x0C
#define M5 0x1E
#define M6 0x3F
#define OFF 0x00

void main()
{
	TRISB = 0x00;
	PORTB = OFF;
	 	
	PORTB = M3;
	delay_ms(20000);
	PORTB = M4;
	delay_ms(20000);
	PORTB = M2;
	delay_ms(20000);
	PORTB = M5;
	delay_ms(10000);
	PORTB = M1;
	delay_ms(10000);
	PORTB = M6;
	delay_ms(30000);
	PORTB = OFF;
}

