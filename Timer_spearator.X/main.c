#include<xc.h>
#include "main.h"
#include "timers.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    LED_ARRAY=0x00;
    LED_ARRAY_DDR=0x00;
    init_timer0();
    init_timer1();
    init_timer2();
}

void main(void)
{
    init_config();
    while(1)
    {
        ;
    }
}