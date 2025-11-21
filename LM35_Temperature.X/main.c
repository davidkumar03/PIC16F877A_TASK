#include<xc.h>
#include "adc.h"
#include "clcd.h"

#pragma config WDTE=OFF
void display(unsigned short adc_value)
{
    int mvolt= adc_value*(4.88);//convert digital value to milli volt => volt= ((adc_value)*(5/1024)) -> volt*1000(we get milli volt)
    int cel=mvolt/10;
    char buff[5];
    int i;
    clcd_print("VALUE:", LINE2(0)); 
    i = 1; 
    do
    {
        buff[i] = (cel % 10) + '0';
        cel = cel / 10; 
    } while (i--); 
    buff[2] = 'o';
    buff[3] = 'C';
    buff[4] = '\0';
    
    clcd_print(buff,LINE2(6));
}
static void init_config(void)
{
    init_adc();
    init_clcd();
    clcd_print("ROOM TEMPERATRUE",LINE1(0));
}

void main(void)
{
    init_config();
    unsigned short adc_reg_val;
    while(1)
    {
        adc_reg_val=read_adc(CHANNEL0);//10 bit value(0 to 1023)
        display(adc_reg_val/10.23);//to convert a 0 to 100zzz
    }
    return;
}