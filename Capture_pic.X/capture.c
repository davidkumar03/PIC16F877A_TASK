/*
 * File:   capture.c
 * Author: davit
 *
 * Created on November 28, 2025, 5:02 PM
 */


#include <xc.h>
#include "capture.h"

void init_capture(void)
{
    T1CON=0x01;
    CCP1CON = 0x06;
    PIE1=0x04;
    INTCON=0xC0;
    CCPR1=0x00;
}
