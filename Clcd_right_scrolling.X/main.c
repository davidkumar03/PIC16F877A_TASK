#include<xc.h>
#include "clcd.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    init_clcd();
}

void main(void)
{
    ADCON1 = 0x06;
    init_config();
    char head[16]="Embedded Is HOT";
    char str[16]="GOOD Evening";
    while(1)
    {
        clcd_print(head,LINE1(0));
        __delay_ms(10);
        clcd_print(str,LINE2(0));
    }
}