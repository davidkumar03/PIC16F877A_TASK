#include<xc.h>
#include "clcd.h"
#include "matrix_keypad.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    init_clcd();
    init_matrix_keypad();
    clcd_print("ENTER PASSWORD",LINE1(0));
}
void display(unsigned char key)
{
    if (key != ALL_RELEASED)
    {        
        switch (key) //'*' '#' 
        {
            case '*':
            case '#':
                clcd_putch('*', LINE2(0)); //* #
                break;
            default: // 0 1 2 3 .. 9
                clcd_putch('*', LINE2(0)); // 1 + '0' -> '1'
        }
    }
}

void main(void)
{
    init_config();
    static unsigned char key;
    char msg[]={0,0,0,0,0,0};
    int pass_len=5;
    while(1)
    {
        unsigned char i=0;
        if(i<=pass_len)
        {
            clcd_print("_",LINE2(i));
            clcd_putch(DISP_ON_AND_CURSOR_OFF,LINE2(i));
            key=read_matrix_keypad(STATE);
            if(key!=ALL_RELEASED)
            {
                msg[i]=key;
                display(key);
            }
            i++;
        }
    }
}