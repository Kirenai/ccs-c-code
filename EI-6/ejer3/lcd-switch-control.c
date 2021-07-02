#include <16f877a.h>
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

#use fast_io(a)
#use fast_io(b)

int i = 0;

void main() {
    set_tris_a(0xFF);
    set_tris_b(0x00);
    output_b(0x00);

    lcd_init();
    lcd_gotoxy(1, 1);
    lcd_putc("Pulse para");
    lcd_putc(1, 2);
    lcd_putc("Inicar conteo");

    while (true) {
        if (input(PIN_A1)) {
            for (i = 0; i <= 10; i++) {
                printf(lcd_putc, "\fConteo %d", i);
                delay_ms(1000);
            }
            lcd_gotoxy(1, 2);
            lcd_putc("Finalizado..");
            output_b(0b00001000);
            delay_ms(5000);
            reset_cpu();
        }
    }
}
