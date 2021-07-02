#include <16f877a.h>
#use delay(clock=4M)
#fuses XT, NOWDT, NOPROTECT, NOLVP, NOBROWNOUT

#define lcd_rs_pin PIN_D0
#define lcd_rw_pin PIN_D1
#define lcd_enable_pin PIN_D2
#define lcd_data4 PIN_D4
#define lcd_data5 PIN_D5
#define lcd_data6 PIN_D6
#define lcd_data7 PIN_D7
#include <lcd.c>

void lcdDesplazarDerecha() {
    lcd_send_byte(0, 0x1C);
}

void lcdDesplazarIzquierda() {
    lcd_send_byte(0, 0x18);
}

void main() {
    lcd_init();
    lcd_putc("Un mensaje giratorio de 40 caracteres!");

    while (true) {
        lcdDesplazarIzquierda();
        delay_ms(5000);
    }
}
