/*  
    Realizar un programa de control de llenado de líquidos de un tanque industrial, que permita
    mostrar los mensajes a través de un display lcd de 16x2, Nivel Bajo, Nivel Medio y Nivel Lleno,
    teniendo como proceso de control a través pic 16f877a. teniendo presente las siguiente
    condiciones:

        - Encender el motor 1 que permite llenar el tanque con tinta de color Azul, luego cuando
        llegue al nivel medio se apague el motor 1.
        - Encender el motor 2 que permite llenar al tanque con la tinta de color Rojo, siempre en
        cuando el tanque esté en el nivel medio, luego cuando llegue al nivel Lleno se apague el
        motor 2.
        - Encender el motor 3 que permite mezclar las tintas que se han almacenado en el tanque
        Industrial por un tiempo de 10 segundos, luego apagar el motor 3.

*/
#include <16f877a.h>
#fuses XT, NOWDT, NOBROWNOUT, NOLVP, NOPROTECT
#use delay(clock=4M)

#define lcd_rs_pin PIN_D0
#define lcd_rw_pin PIN_D1
#define lcd_enable_pin PIN_D2
#define lcd_data4 PIN_D4
#define lcd_data5 PIN_D5
#define lcd_data6 PIN_D6
#define lcd_data7 PIN_D7
#include <lcd.c>

#byte TRISB = 0x86
#byte PORTB = 0x06

#define L  PIN_A0
#define M  PIN_A1
#define H  PIN_A2

void main()
{
    lcd_init();
    lcd_putc('\f');
    delay_ms(100);

    TRISB = 0x00000000;
    PORTB = 0x00;

    int nivel1 = 1;
    int nivel2 = 1;
    int nivel3 = 1;

    while(true)
    {
        if (input(L) == 0)
        {
            lcd_putc('\f');
            lcd_gotoxy(1, 1);
            printf(lcd_putc, "Tanque Vacio");
            PORTB = 0b00000000;
        }

        if (input(L) == 1 && nivel1 == 1)
        {
            PORTB = 0b00000001;
            lcd_gotoxy(4, 1);
            printf(lcd_putc, "\fNivel Bajo");
        }

        if (input(M) == 1 && nivel2 == 1)
        {
            PORTB = 0b00000010;
            nivel1 = 2;
            lcd_gotoxy(4, 1);
            printf(lcd_putc, "\fNivel Medio");
        } else 
        {
            nivel1 = 1;
        }

        if (input(H) == 1 && nivel3 == 1)
        {
            nivel1 = 2;
            nivel2 = 2;
            lcd_gotoxy(4, 1);
            printf(lcd_putc, "\fNivel Lleno");
            PORTB = 0b00000100;
            delay_ms(10000);
            PORTB = 0b00000000;
            lcd_gotoxy(1, 1);
            printf(lcd_putc, "\fProceso");
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "Terminado");
            break;
        } else 
        {
            nivel2 = 1;
        }

        delay_ms(2000);
    }

}
