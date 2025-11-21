#include<xc.h>
#include "digital_keypad.h"
#include "ssd.h"

#pragma config WDTE=OFF
#define SIZE 12

static void init_config(void)
{
    init_ssd();
    init_digital_keypad();
}

void main(void)
{
    init_config();
    static unsigned char ssd[MAX_SSD_CNT];//
    static unsigned char digit[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,SPACE};//a
    unsigned int flag=0,wait=0;
    static unsigned char key,pre_key=ALL_RELEASED;
    int arr[SIZE]={8,8,7,0,4,5,1,4,7,8,10,10};//num
    while(1)
    {
        if(flag==0)
        {
            flag=1;
            int i=0;
            ssd[0]=digit[(arr[i])];
            ssd[1]=digit[(arr[i+1])];
            ssd[2]=digit[(arr[i+2])];
            ssd[3]=digit[(arr[i+3])];
        }
        key=read_digital_keypad(STATE);
        if(key!=ALL_RELEASED)
        {
            pre_key=key;
        }
        if(wait++ ==75)
        {
            wait=0;
            if((flag==1)&&(pre_key==ALL_RELEASED))
            {
                int temp=arr[0];
                for(int i=1;i<SIZE;i++)
                {
                    arr[i-1]=arr[i];
                }
                arr[SIZE-1]=temp;
                int i=0;
                ssd[0]=digit[(arr[i])];
                ssd[1]=digit[(arr[i+1])];
                ssd[2]=digit[(arr[i+2])];
                ssd[3]=digit[(arr[i+3])];
            }
            else if((flag==1)&&(pre_key==SW1))
            {
                int temp=arr[SIZE-1];
                for(int i=SIZE-1;i>0;i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[0]=temp;
                int i=0;
                ssd[0]=digit[(arr[i])];
                ssd[1]=digit[(arr[i+1])];
                ssd[2]=digit[(arr[i+2])];
                ssd[3]=digit[(arr[i+3])];
            }
            else if((flag==1)&&(pre_key==SW2))
            {
                int temp=arr[0];
                for(int i=1;i<SIZE;i++)
                {
                    arr[i-1]=arr[i];
                }
                arr[SIZE-1]=temp;
                int i=0;
                ssd[0]=digit[(arr[i])];
                ssd[1]=digit[(arr[i+1])];
                ssd[2]=digit[(arr[i+2])];
                ssd[3]=digit[(arr[i+3])];
            }
            else
            {
                flag=0;
            }
        }
        display(ssd);
    }
}