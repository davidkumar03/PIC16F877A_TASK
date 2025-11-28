/*
 * File:   compare.c
 * Author: davit
 *
 * Created on November 27, 2025, 6:23 PM
 */


#include <xc.h>
#include "compare.h"

void compare_init(void)
{
    T1CON = 0x01; //Timer 1 ON
    TMR1 = 0;
    CCPR1 = 100;
    CCP1CON = 0x0B;
    CCP1IE =1;
    
}
