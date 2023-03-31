/********************************************************************************
* isr.c: Innehåller avbrottsrutiner.
********************************************************************************/
#include "display.h"
#include "button.h"

/********************************************************************************
* ISR (TIMER1_COMPA_vect): Avbrottsrutin som äger rum vid uppräkning till 256 av
*                          Timer 1 i CTC Mode, vilket sker var 0.128:e
*                          millisekund när timern är aktiverad. En gång per
*                          millisekund togglas talet utskrivet på 
*                          7-segmentsdisplayerna mellan tiotal och ental.
********************************************************************************/
ISR (TIMER1_COMPA_vect)
{
   display_toggle_digit();
   return;
}

/********************************************************************************
* ISR (TIMER2_OVF_vect): Avbrottsrutin som äger rum vid uppräkning till 256 av
*                        Timer 2 i Normal Mode, vilket sker var 0.128:e
*                        millisekund när timern är aktiverad. En gång per sekund
*                        inkrementeras talet utskrivet på 7-segmentsdisplayerna.
********************************************************************************/
ISR (TIMER2_OVF_vect)
{
   display_count();
   return;
}

/********************************************************************************
* ISR (PCINT0_vect):
********************************************************************************/
ISR (PCINT0_vect)
{
	if(BUTTON1_IS_PRESSED)
	{
		display_toggle_output();
	}
	
	if(BUTTON2_IS_PRESSED)
	{
		display_toggle_count_direction();
	}
	
	if(BUTTON3_IS_PRESSED)
	{
		display_toggle_count();
	}
	
	return;
}