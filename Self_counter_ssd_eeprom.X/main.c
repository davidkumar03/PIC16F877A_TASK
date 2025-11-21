#include<xc.h>
#include "digital_keypad.h"
#include "ssd.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    init_digital_keypad();
    init_ssd();
}

void memory_write(unsigned int count)
{
    eeprom_write(0x00,(count/1000));
    eeprom_write(0x01,((count/100)%10));
    eeprom_write(0x02,((count/10)%10));
    eeprom_write(0x03,(count%10));
}

void main(void)
{
    init_config();
    static unsigned char key;
    static unsigned int count=0;
    static unsigned int flag=0,wait=0;
    unsigned char digit[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    unsigned char ssd[MAX_SSD_CNT];
    while(1)
    {
        key=read_digital_keypad(STATE);
        if(key==SW2)
        {
            memory_write(count);
        }
        if(wait++ == 75)
        {
            wait=0;
            if(flag == 0)
            {
                 count=1000*eeprom_read(0x00)+100*eeprom_read(0x01)+10*eeprom_read(0x02)+ eeprom_read(0x03);
                 flag=1;
            }
            else
            {
                count++;
            }
            if(count > 9999)
            {
                count=0;
            }
            ssd[3] = digit[count%10]; // count%10 : 7 : digits[count%10] : digits[7]
            ssd[2] = digit[(count/10)%10]; //count/10 : 456%10 : 6
            ssd[1] = digit[(count/100)%10]; //count/100: 45%10 : 5
            ssd[0] = digit[count/1000]; 
         }
        // Display the digits
        display(ssd);

    }
}