/* 
 * File:   main.h
 * Author: ACER
 *
 * Created on March 6, 2025, 11:35 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#define LED_ARRAY PORTB
#define LED_ARRAY_DDR TRISB

#define LED RB0
#define ON 1
#define OFF 0
#define PERIOD 100
extern volatile unsigned short adc_reg_val;

#endif	/* MAIN_H */

