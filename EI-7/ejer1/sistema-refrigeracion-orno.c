#include <16f877a.h>
#device ADC=10
#use delay(clock=4M)
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP

#define lcd_rs_pin PIN_D0
#define lcd_rw_pin PIN_D1
#define lcd_enable_pin PIN_D2
#define lcd_data4 PIN_D4
#define lcd_data5 PIN_D5
#define lcd_data6 PIN_D6
#define lcd_data7 PIN_D7
#include <lcd.c>

float temperatura = 0.0;

void main() 
{

    // Conversion--------------------
    //Habilitando el puerto RA0 en analogo, ALL_ANALOG para todo
    setup_adc_ports(RA0_ANALOG); 
    setup_adc(ADC_CLOCK_INTERNAL);
    // Como entrada
    set_adc_channel(0);
    //---------------------------
    lcd_init();
    lcd_gotoxy(1, 1);
    printf(lcd_putc, "Temperatura");
    delay_ms(350);

    while (true) 
    {
        temperatura = read_adc() * 0.4882;
        lcd_gotoxy(1, 1);
        printf(lcd_putc, "Temperatura: %f Grados", temperatura);
        delay_ms(250);

        if (temperatura >= 35) 
        {
            output_high(pin_b0);
            output_high(pin_b1);
            output_low(pin_b2);
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "Disipando calor");
            delay_ms(600);
        } else 
        {
            output_low(pin_b0);
            output_low(pin_b1);
            output_high(pin_b2);
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "Correctamente");
            delay_ms(600);
        }
    }
}
