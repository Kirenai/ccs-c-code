# include <16f628a.h>
# fuses NOWDT, XT
# use DELAY(clock=4M)
# use standard_io(b)

void main()
{
   while(true)
   {
      output_high(PIN_B0);
      delay_ms(1000);
      output_low(PIN_B0);
      delay_ms(1000);
   }
}
