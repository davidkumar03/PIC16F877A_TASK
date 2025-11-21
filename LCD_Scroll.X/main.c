/*
 * File:   main.c
 * Author: davit
 *
 * Created on November 10, 2025, 5:30 AM
 */


#include <xc.h>
#include "lcd.h"
#pragma config WDTE=OFF
void main(void) {
    lcd_init();
    const char str[]="Hardware and software combination";
    clcd_print(str,LINE1(0));
    while(1)
    {
        lcd_right_scroll(40);
        __delay_ms(100);
        lcd_left_scroll(40);
        __delay_ms(100);
    }
    return;
}
