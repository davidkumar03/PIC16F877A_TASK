/*
 * File:   isr.c
 * Author: davit
 *
 * Created on November 28, 2025, 5:37 PM
 */


#include <xc.h>
#include"main.h" 

void __interrupt() isr(void)
{
      if(CCP1IF)
      {
        CCP1IF=0;
        LED_PORT=~LED_PORT;
      }
}
