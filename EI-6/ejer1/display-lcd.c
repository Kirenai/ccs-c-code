#include <16f877a.h>
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP
#use delay(clock=4M)

#define lcd_rs_pin PIN_D0
#define lcd_rw_pin PIN_D1
#define lcd_enable_pin PIN_D2
#define lcd_data4 PIN_D4
#define lcd_data5 PIN_D5
#define lcd_data6 PIN_D6
#define lcd_data7 PIN_D7
#include <lcd.c>

void main()
{
	lcd_init();  //Iniciando el lcd
	lcd_gotoxy(1, 1); //Cordenadas de salida
	lcd_putc("Mensaje desde"); //Mensaje de salida en la cordenada
	lcd_gotoxy(1, 2); //Cordenadas de salida
	lcd_putc("Pantalla LCD :)"); //Mensaje de salida en la cordenada
  	
	while(true) {
										  	
	}	    
}

