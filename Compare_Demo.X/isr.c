/*
 * File:   isr.c
 * Author: davit
 *
 * Created on November 27, 2025, 6:24 PM
 */


#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned int count=0;
    if(CCP1IF==1)
    {
        if(count==80)
        {
            PIN =~PIN;
            count=0;
        }
        count++;
        CCP1IF=0;
    }
}
