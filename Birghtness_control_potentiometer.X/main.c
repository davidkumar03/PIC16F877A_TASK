#include<xc.h>
#include "main.h"
#include "adc.h"

#pragma config WDTE=OFF
#define PERIOD 100
static void init_config(void)
{
    LED_ARRAY=0x00;//PORTD ALL are off condition
    LED_ARRAY_DDR=0x00; // Assign PORTD as a output
    init_adc();
}
void software_pwm(unsigned short duty_cycle)
{
    static unsigned short loop_count=0;
    if(loop_count<=(duty_cycle/10.23))
    {
        LED = ON;
    }
    else 
    {
        LED = OFF;
    }
    if(loop_count==PERIOD)
    {
        loop_count=0;
    }
    loop_count++;
}
void main(void)
{
    unsigned short adc_reg_value;
    init_config();
    while(1)
    {
        adc_reg_value=read_adc(CHANNEL2); // 0 to 1023 (10 bit)
        software_pwm(adc_reg_value);
    }
    return;
}