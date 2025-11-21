#include<xc.h>
#include "digital_keypad.h"
#include "ssd.h"

#pragma config WDTE=OFF

static unsigned int count = 0;
static unsigned int press_duration = 0;
static unsigned char pre_key1 = ALL_RELEASED,pre_key2= ALL_RELEASED;

#define LONG_PRESS_TIME 100 

unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

static void init_config(void)
{
    init_ssd();
    init_digital_keypad();
}
void main(void)
{
    init_config();
    unsigned char key1,key2;
    unsigned char ssd[MAX_SSD_CNT];
    while(1)
    {
        key1 = read_digital_keypad(LEVEL);
        key2 = read_digital_keypad(STATE);
        
        if(key1 != pre_key1)
        {
            if (key1 == SW1 && pre_key1 == ALL_RELEASED)
            {
                press_duration = 0;
            }
            if (key1 == ALL_RELEASED && pre_key1 == SW1)
            {
                press_duration = 0;
            }
            pre_key1 = key1; 
        }
        if(key2 != pre_key2)
        {
            if (key2 == SW1 && pre_key2 == ALL_RELEASED)
            {
                press_duration = 0;
            }
            if (key2 == ALL_RELEASED && pre_key2 == SW1)
            {
                press_duration = 0;
            }
            pre_key2 = key2; 
        }
        if (pre_key1 == SW1)
        {
            press_duration++;
            if (press_duration > LONG_PRESS_TIME) 
            {
                count = 0;
            }
        }
        if(pre_key2 == SW1)
        {
            count++;
        }
        if (count >= 10000)
        {
            count = 0;
        }
        ssd[0] = digit[(count / 1000)];
        ssd[1] = digit[(count % 1000) / 100];
        ssd[2] = digit[(count % 100) / 10];
        ssd[3] = digit[(count % 10)];

        // Display the digits
        display(ssd);
    }
}
