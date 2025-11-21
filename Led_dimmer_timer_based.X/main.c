#include<xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "timers.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    LED_ARRAY=0x00;//PORTD ALL LEDS are off
    LED_ARRAY_DDR=0x00; //PORTD assigned as a output
    init_digital_keypad();
    init_timer0();
}
volatile unsigned int duty_cycle=50;
void software_pwm(unsigned char key)
{
    static unsigned int wait=0;
    if(++wait == 500)
    {
        wait=0;
        if(key==SW1)
        {
            if(duty_cycle< PERIOD)
            {
                duty_cycle++;
            }
        }
        else if(key==SW2)
        {
            if(duty_cycle > 0)
            {
                duty_cycle--;
            }
        }
    }
   
}
void main(void)
{
    unsigned char key;
    init_config();
    while(1)
    {
        key=read_digital_keypad(LEVEL);
        software_pwm(key);
    }
}
