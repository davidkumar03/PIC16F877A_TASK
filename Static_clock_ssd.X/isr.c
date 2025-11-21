#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned long int count=0;
    static unsigned long int count1=0;
    
    if (TMR0IF == 1)
    {
        /* TMR0 Register valur + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 6 + 2;
        
        if (count++ == 10000)
        {
            count=0;
            flag = !flag;
        }
        if (count1++ == 20000)
        {
            count1=0;
            min++;
            if(min==MIN_LIMIT)
            {
                min=0;
                hour++;
                if(hour==HOUR_LIMIT)
                {
                    hour=0;
                }
            }
        }
        TMR0IF = 0;
    }
}