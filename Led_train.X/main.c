#include<xc.h>
#include "main.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    LED_ARRAY=0x00;//portb leds should off
    LED_ARRAY_DDR=0x00;//set portb as output
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
    unsigned char i;
    unsigned char direction=0;
    while(1)
    {
        if(direction==0)
        {
            for(int i=0;i<8;i++)
            {
                LED_ARRAY=LED_ARRAY | (1<<i);
                delay_ms(250);
            }
            for(int i=0;i<8;i++)
            {
                LED_ARRAY=LED_ARRAY & (~(1<<i));
                delay_ms(250);
            }
            direction=1;
        }
        if(direction==1)
        {
            for(int i=7;i>=0;i--)
            {
                LED_ARRAY=LED_ARRAY | (1<<i);
                delay_ms(250);
            }
            for(int i=7;i>=0;i--)
            {
                LED_ARRAY=LED_ARRAY & (~(1<<i));
                delay_ms(250);
            }
            direction=0;
        }
    }
}
