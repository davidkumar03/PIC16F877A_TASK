#include <xc.h>
#include "main.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    LED_ARRAY=0x00;
    LED_ARRAY_DDR=0x00;
}
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 1000; j++); // Approximate delay loop
    }
}

void main(void)
{
    init_config();
    static unsigned int direction=0;
    while(1)
    {
        if(direction == 0)
        {
            int LED=0;
            LED_ARRAY=0x00;
            LED_ARRAY=LED_ARRAY|(1<<LED++);//1<<0++  1<<0
            LED_ARRAY=LED_ARRAY|(1<<5);
            delay_ms(3000);
            LED_ARRAY=0x00;
            LED_ARRAY=LED_ARRAY|(1<<LED++);//1<<1
            LED_ARRAY=LED_ARRAY|(1<<4);
            delay_ms(1000);
            LED_ARRAY=0x00;
            LED_ARRAY=LED_ARRAY|(1<<LED++);
            LED_ARRAY=LED_ARRAY|(1<<3);
            delay_ms(3000);
            direction=1;
        }
        if(direction == 1)
        {
            int LED=3;
            LED_ARRAY=0x00;
            LED_ARRAY=LED_ARRAY|(1<<LED++);
            LED_ARRAY=LED_ARRAY|(1<<2);
            delay_ms(3000);
            LED_ARRAY=0x00;
            LED_ARRAY=LED_ARRAY|(1<<LED++);
            LED_ARRAY=LED_ARRAY|(1<<1);
            delay_ms(1000);
            LED_ARRAY=0x00;
            LED_ARRAY=LED_ARRAY|(1<<LED++);
            LED_ARRAY=LED_ARRAY|(1<<0);
            delay_ms(3000);
           
            direction=0;
        }
    }
}