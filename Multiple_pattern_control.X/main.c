#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF

static void init_config() {
    LED_ARRAY = 0x00;
    LED_ARRAY_DDR = 0x00;
    init_digital_keypad();
}

void multiple_pattern(unsigned char pre_key);

void main(void) {
    unsigned char key, pre_key = ALL_RELEASED;
    init_config();
    while(1) {
        key = read_digital_keypad(STATE);
        if(key != ALL_RELEASED) {
            pre_key = key;
        }
        multiple_pattern(pre_key);
    }
}

void multiple_pattern(unsigned char pre_key) {
    static unsigned long delay = 0;
    static unsigned int i = 0, j = 0, k = 0;
    static unsigned char flag = 0;

    if(delay++ == 10000) {
        delay = 0;
        flag = !flag;

        switch(pre_key) {
            case SW1:
                if(i < 8)
                {
                    LED_ARRAY |= (1 << i++);
                } 
                else if(i < 16) 
                {
                    LED_ARRAY &= ~(1 << (i++ - 8));
                } 
                else if(j < 8) 
                {
                    LED_ARRAY |= (1 << (7 - j++));
                }
                else if(j < 16) 
                {
                    LED_ARRAY &= ~(1 << (15 - j++));
                }
                if(i == 16 && j == 16) {
                    i = j = 0;
                }
                break;

            case SW2:
                if(k < 8) {
                    LED_ARRAY |= (1 << k++);
                } else if(k < 16) {
                    LED_ARRAY &= ~(1 << (k++ - 8));
                }
                if(k == 16) {
                    k = 0;
                }
                break;

            case SW3:
                LED_ARRAY = flag ? 0xAA : ~0xAA;
                break;

            case SW4:
                LED_ARRAY = flag ? 0x0F : ~0x0F;
                break;

            default:
                LED_ARRAY = 0x00;
                break;
        }
    }
}
