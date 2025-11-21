/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "timers.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

#define PERIOD              100
volatile unsigned int duty_cycle = 10;
void software_pwm(unsigned char key)
{
    static unsigned char loop_counter;
    static unsigned int wait = 0;
    
    if (++wait == 200)
    {
        wait = 0;
        
        if (key == SW1)
        {
            duty_cycle=100;
            TMR0IE=1;
        }
    }
 
    if (loop_counter <= duty_cycle)
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
    
    if (loop_counter == PERIOD)
    {
        loop_counter = 0;
    }
    
    loop_counter++;
}

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
    init_timer0();
   /*Global interrupt enable*/
    GIE=1;
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1) {
        key = read_digital_keypad(STATE);
        
        software_pwm(key);
    }
    return;
}
