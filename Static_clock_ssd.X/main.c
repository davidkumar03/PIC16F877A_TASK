#include<xc.h>
#include "ssd.h"
#include "timers.h"
#include "main.h"

#pragma config WDTE=OFF

volatile unsigned int hour=12;
volatile unsigned int min=00;
volatile unsigned int flag=0;
static void init_config(void)
{
    init_ssd();
    init_timer0();
    /*Global interrupt enable bit*/
    GIE =1;
    /*pripheral interrupt enable bit*/
    //PEIE=1;
    
}


void main(void)
{
    init_config();
    unsigned char digit[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,DP};
    unsigned char ssd[MAX_SSD_CNT];
    while(1)
    {
        if(flag)
        {
            ssd[0]=digit[hour/10];//1
            ssd[1]=((digit[hour%10])|(digit[10]));//2.
            ssd[2]=digit[min/10];//0
            ssd[3]=digit[min%10];//0
        }
        else
        {
            ssd[0]=digit[hour/10];//1
            ssd[1]=digit[hour%10];
            ssd[2]=digit[min/10];
            ssd[3]=digit[min%10];
        }
        display(ssd);
    }
}