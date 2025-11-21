#include<xc.h>
#include "digital_keypad.h"
#include "ssd.h"
#include "ds1307.h"
#include "i2c.h"

#pragma config WDTE=OFF

#define LONG_PRESS_TIME 100

static void init_config(void)
{
    init_digital_keypad();
    init_ssd();
    init_i2c(100000);//100K
    init_eeprom();
}

void memory_write(unsigned int count)
{
    write_eeprom(0x00,(count/1000));
    write_eeprom(0x01,((count/100)%10));
    write_eeprom(0x02,((count/10)%10));
    write_eeprom(0x03,(count%10));
}

void main(void)
{
    init_config();
    static unsigned char key1,key2;
    static unsigned char pre_key1=ALL_RELEASED,pre_key2=ALL_RELEASED;
    static unsigned char press_duration=0;
    static unsigned int count=0;
    static unsigned int flag=0;
    unsigned char digit[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
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
            count=count+1;
        }
        if(key1==SW2)
        {
            memory_write(count);
        }
        if(count > 10000)
        {
            count=0;
        }
        if(flag == 0)
        {
            count=1000*read_eeprom(0x00)+100*read_eeprom(0x01)+10*read_eeprom(0x02)+ read_eeprom(0x03);
            flag=1;
        }
        ssd[3] = digit[count%10]; // count%10 : 7 : digits[count%10] : digits[7]
        ssd[2] = digit[(count/10)%10]; //count/10 : 456%10 : 6
        ssd[1] = digit[(count/100)%10]; //count/100: 45%10 : 5
        ssd[0] = digit[count/1000]; 
        // Display the digits
        display(ssd);

    }
}