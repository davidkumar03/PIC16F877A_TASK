#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned int loop_count = 0;
    
    if (TMR0IF == 1)
    {
        /* TMR0 Register valur + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 6 + 2;
        
        if(loop_count<=duty_cycle)
        {
            LED = ON;
        }
        else
        {
            LED=OFF;
        }
        loop_count++;
        
        if(loop_count==PERIOD)
        {
            loop_count=0;
        }
        TMR0IF=0;
    }
}