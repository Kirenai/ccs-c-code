#include <16f877a.h>
#fuses HS, NOPROTECT, NOBROWNOUT, NOLVP, NOWDT, NOPUT
#use delay(clock=20M)
#use rs232(baud=9600, bits=8, parity=N, xmit=PIN_C6, rcv=PIN_C7)
#include <stdio.h>

#define lcd_rs_pin PIN_D0
#define lcd_rw_pin PIN_D1
#define lcd_enable_pin PIN_D2
#define lcd_data4 PIN_D4
#define lcd_data5 PIN_D5
#define lcd_data6 PIN_D6
#define lcd_data7 PIN_D7
#include <lcd.c>

#define led_1 PIN_B0
#define led_2 PIN_B1

#byte TRISB = 0x86
#byte PORTB = 0x06

char data_rx;

void main()
{
    TRISB = 0x00;
    PORTB = 0x00;
    lcd_init();
    lcd_gotoxy(1, 1);
    lcd_putc("\fEncendiendo");
    delay_ms(500);
    lcd_gotoxy(1, 2);
    lcd_putc("Sistema..");
    delay_ms(500);
    lcd_putc("\fMotores apagados");
    delay_ms(500);
    
    while (true)
    {
        if (kbhit())
        {
            data_rx = getc();

            switch (data_rx) 
            {
                case 'a':
                    PORTB = 0b00000001;
                    lcd_putc('\f');
                    lcd_gotoxy(1, 1);
                    printf(lcd_putc, "Motor 1");
                    lcd_gotoxy(1, 2);
                    printf(lcd_putc, "Encendido");
                    break;
                case 'b':
                    PORTB = 0b00000000;
                    lcd_putc('\f');
                    lcd_gotoxy(1, 1);
                    printf(lcd_putc, "Motor 1");
                    lcd_gotoxy(1, 2);
                    printf(lcd_putc, "Apagado");
                    break;
                case 'c':
                    PORTB = 0b00000010;
                    lcd_putc('\f');
                    lcd_gotoxy(1, 1);
                    printf(lcd_putc, "Motor 2");
                    lcd_gotoxy(1, 2);
                    printf(lcd_putc, "Encendido");
                    break;
                case 'd':
                    PORTB = 0b00000000;
                    lcd_putc('\f');
                    lcd_gotoxy(1, 1);
                    printf(lcd_putc, "Motor 2");
                    lcd_gotoxy(1, 2);
                    printf(lcd_putc, "Apagado");
                    break;
                case 'e':
                    PORTB = 0b00000011;
                    lcd_putc('\f');
                    lcd_gotoxy(1, 1);
                    printf(lcd_putc, "Motor 1 y 2");
                    lcd_gotoxy(1, 2);
                    printf(lcd_putc, "Encendidos");
                    break;
                case 'f':
                    PORTB = 0b00000000;
                    lcd_putc('\f');
                    lcd_gotoxy(1, 1);
                    printf(lcd_putc, "Motor 1 y 2");
                    lcd_gotoxy(1, 2);
                    printf(lcd_putc, "Apagados");
                    break;
            }
        }
    }
}
