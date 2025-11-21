#include<xc.h>
#include "main.h"
#include "adc.h"
#include "timers.h"

#pragma config WDTE=OFF

volatile unsigned short adc_reg_val;

static void init_config(void)
{
    LED_ARRAY=0x00;
    LED_ARRAY_DDR=0x00;
    init_adc();
    init_timer0();
}

void main(void)
{
    init_config();
    while(1)
    {
        adc_reg_val= read_adc(CHANNEL1);
    }
}