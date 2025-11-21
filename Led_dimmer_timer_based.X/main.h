/* 
 * File:   main.h
 * Author: ACER
 *
 * Created on March 6, 2025, 10:02 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#define LED_ARRAY  PORTD
#define LED_ARRAY_DDR TRISD

#define LED  RD0

#define ON   1
#define OFF  0

#define PERIOD 100

extern volatile unsigned int duty_cycle;

#endif	/* MAIN_H */

