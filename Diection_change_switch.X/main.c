#include<xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    LED_ARRAY = 0x00;//PORTD All LED should off
    LED_ARRAY_DDR =0x00;//PORTD Configured as output
    init_digital_keypad();
}
void direction_control(unsigned char pre_key);
void main(void)
{
    init_config();
    unsigned char key,pre_key;
    while(1)
    {
        key=read_digital_keypad(STATE);
        if(key!=ALL_RELEASED)
        {
            pre_key=key;
        }
        direction_control(pre_key);
    }
}
    void direction_control(unsigned char pre_key)
    {
        static unsigned int i=0;
        static unsigned long delay=0;
        if(delay++ == 10000)
        {
            delay=0;
            if(pre_key==SW1)
            {
                if(i<8)
                {
                    LED_ARRAY = LED_ARRAY |(1<<i++);
                }
                else if(i<16)
                {
                    LED_ARRAY = LED_ARRAY &(~(1<<(i++-8)));
                }
                if(i==16)
                    i=0;
            }
            if(pre_key==SW2)
            {
                if(i<8)
                {
                    LED_ARRAY = LED_ARRAY | (1<< (7-i++));
                }
                else if(i<16)
                {
                    LED_ARRAY = LED_ARRAY & (~(1<<(15-i++)));
                }
                if(i==16)
                    i=0;
            }
        }
    }