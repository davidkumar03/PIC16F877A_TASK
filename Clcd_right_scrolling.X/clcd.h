/* 
 * File:   clcd.h
 */

#ifndef CLCD_H
#define	CLCD_H

#define _XTAL_FREQ                  20000000//20MHZ

#define CLCD_DATA_PORT              PORTD
#define CLCD_DATA_PORT_DDR          TRISD
#define CLCD_RS                     RE2
#define CLCD_EN                     RE1
#define CLCD_RS_DDR                 TRISE2
#define CLCD_EN_DDR                 TRISE1

#define INST_MODE                   0
#define DATA_MODE                   1

#define HI                          1
#define LOW                         0

#define LINE1(x)                    (0x80 + x)
#define LINE2(x)                    (0xC0 + x)

#define EIGHT_BIT_MODE              0x30  // 0x 0011(DL) 0011 
#define FOUR_BIT_MODE               0x23  // 0x 0010    0011
#define TWO_LINES_5x8_8_BIT_MODE    0x38  // 0x 0011  (N)10(F)00
#define CLEAR_DISP_SCREEN           0x01  // 0x 0000 0001(C)
#define DISP_ON_AND_CURSOR_OFF      0x0C  //0x0000 11(D)00

void init_clcd(void);
void clcd_putch(const char data, unsigned char addr);
void clcd_print(const char *str, unsigned char addr);

#endif	/* CLCD_H */

