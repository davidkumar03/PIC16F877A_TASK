/*
 * File:   lcd.c
 * Author: davit
 *
 * Created on November 10, 2025, 5:30 AM
 */


#include <xc.h>
#include "lcd.h"
static void clcd_write(unsigned char byte,unsigned char mode)
{
    RS = mode;
    LCD_DATA_PORT = byte;
    EN = HI;
    __delay_us(100);
    EN=LOW;
    
    __delay_us(4100);
}
static void init_display(void)
{
    __delay_ms(30);
    clcd_write(EIGHT_BIT_MODE,INST_MODE);
    __delay_ms(4100);
    clcd_write(EIGHT_BIT_MODE,INST_MODE);
    __delay_us(100);
    clcd_write(EIGHT_BIT_MODE,INST_MODE);
    __delay_us(1);
    clcd_write(TWO_LINE_8_BIT_MODE,INST_MODE);
    __delay_us(500);
    clcd_write(DISPLAY_ON,INST_MODE);
    __delay_us(500);
    clcd_write(CLEAR_DISPLAY,INST_MODE);
    __delay_us(500);    
}
void lcd_init(void)
{
    LCD_DATA_REG =0x00;
    RS_DR=0;
    EN_DR=0;
    init_display();
}

void clcd_print(const char *str,unsigned char addr)
{
    clcd_write(addr,INST_MODE);
    while(*str)
    {
        clcd_write(*str,DATA_MODE);
        str++;
    }
}

void lcd_right_scroll(unsigned char times)
{
    for(int i=0;i<times;i++)
    {
        clcd_write(RIGHT_SCROLL,INST_MODE);
        __delay_ms(200);
    }
}

void lcd_left_scroll(unsigned char times)
{
    for(int i=0;i<times;i++)
    {
        clcd_write(LEFT_SCROLL,INST_MODE);
        __delay_ms(200);
    }
}