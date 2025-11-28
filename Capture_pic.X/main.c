/*
 * File:   main.c
 * Author: davit
 *
 * Created on November 28, 2025, 5:01 PM
 */


#include <xc.h>
#include "main.h"
#include "capture.h"

#pragma config WDTE=OFF

static void init_config(void)
{
    SW_PORT=0x00;
    LED_PORT=0x00;
    SW_DDR=0x04;//0000 0100
    LED_DDR=0x00;
    init_capture();
}
void main(void) {
    init_config();
    while(1)
    {
        ;
    }
    return;
}
