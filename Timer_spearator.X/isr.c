#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned int count=0,count1=0,count2=0;
    
    if (TMR0IF == 1)
    {
        /* TMR0 Register valur + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 6 + 2;
        if(++count == 10000)
        {
            count=0;
            LED1=!LED1;
        }
        TMR0IF=0;
    }
    if (TMR1IF == 1)
    {
        if(++count1 == 40)
        {
            count1 = 0;
            
            LED2 = !LED2;
        }
        TMR1IF = 0;        
    }

    
    if (TMR2IF == 1)
    {
        if (++count2 == 10000)
        {
            count2 = 0;
            
            LED3 = !LED3;
        }
        
        TMR2IF = 0;
    }

}