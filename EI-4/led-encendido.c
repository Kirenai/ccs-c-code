#include <16f628a.h>
#fuses NOWDT, XT // NOWDT = para desactivar el whatdog
#use delay(clock=4M)

#BYTE TRISB = 0X86

void main()
{
   TRISB = 0x00;
   output_b(0x00);
   
   while(true)
   {
      output_high(PIN_B0);
      output_high(PIN_B1);
      delay_ms(1000);
      output_low(PIN_B0);
      output_low(PIN_B1);
      delay_ms(1000);
   }
}
