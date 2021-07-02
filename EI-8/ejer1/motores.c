#include <16f877a.h>
#device ADC=10
#use delay(clock=4M)
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, PUT

#define lcd_rs_pin PIN_D0
#define lcd_rw_pin PIN_D1
#define lcd_enable_pin PIN_D2
#define lcd_data4 PIN_D4
#define lcd_data5 PIN_D5
#define lcd_data6 PIN_D6
#define lcd_data7 PIN_D7
#include <lcd.c>

#define H PIN_B0
#define M1 PIN_B1
#define M2 PIN_B2
#define M3 PIN_B3
#define M4 PIN_B4
#define VENTILADOR PIN_B5

#byte TRISB = 0x86
#byte PORTB = 0x06

float temperatura = 0.0;

void main() 
{
    setup_adc_ports(RA0_ANALOG); 
    setup_adc(ADC_CLOCK_INTERNAL);
    set_adc_channel(0);
    //---------------------------
    lcd_init();
    lcd_gotoxy(1, 1);
    printf(lcd_putc, "Temperatura");
    delay_ms(350);
    TRISB = 0x00;
    PORTB = 0b00000001;   
    
    while (true) 
    {
        temperatura = read_adc() * 0.4882;
        lcd_gotoxy(1, 1);
        printf(lcd_putc, "Temperatura: %f Grados", temperatura);
        delay_ms(500);
        
        if (temperatura >= 100)
        {
            output_low(M1);
            output_low(M2);
            output_low(M3);
            output_low(M4);
            output_low(H);
            output_high(VENTILADOR);
            lcd_gotoxy(1, 1);
            printf(lcd_putc, "SISTEMA APAGADO");
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "VENTILADOR ACTIVADO");
            delay_ms(100);
        } else if (temperatura >= 80) 
        {
            output_high(H);
            output_low(M1);
            output_low(M2);
            output_high(M3);
            output_high(M4);
            output_low(VENTILADOR);
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "MOTOR 3 y 4 ACTIV");
            delay_ms(500);
        } else if (temperatura >= 60) 
        {
            output_high(H);
            output_high(M1);
            output_high(M2);
            output_low(M3);
            output_low(M4);
            output_low(VENTILADOR);
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "MOTOR 1 y 2 ACTIV");
            delay_ms(500);
        } else if (temperatura >= 40) 
        {
            output_high(H);
            output_high(M1);
            output_low(M2);
            output_low(M3);
            output_low(M4);
            output_low(VENTILADOR);
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "MOTOR 1 ACTIV");
            delay_ms(500);
        } else 
        {
            output_high(H);
            output_low(M1);
            output_low(M2);
            output_low(M3);
            output_low(M4);
            output_low(VENTILADOR);
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "                ");
            delay_ms(500);
        }
    }
}

