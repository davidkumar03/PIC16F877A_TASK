/*
 * File:   main.c
 * Author: davit
 *
 * Created on November 27, 2025, 6:23 PM
 */


#include <xc.h>
#include "main.h"
#include "compare.h"

#pragma config WDTE=OFF
static void init_config()
{
    PORT=0x00;
    DDR=0x00;
    compare_init();
    GIE=1;
    PEIE=1;
}
void main(void) {
    init_config();
    while(1)
    {
        ;
    }
    return;
}
