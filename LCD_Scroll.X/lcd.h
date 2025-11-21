/* 
 * File:   lcd.h
 * Author: davit
 *
 * Created on November 10, 2025, 5:31 AM
 */

#ifndef LCD_H
#define	LCD_H
#define _XTAL_FREQ     20000000

#define LCD_DATA_PORT  PORTB
#define LCD_DATA_REG   TRISB

#define RS             RC0
#define RS_DR          TRISC0
#define EN             RC1
#define EN_DR          TRISC1

#define READ           1
#define WRITE          0

#define INST_MODE      0
#define DATA_MODE      1

#define HI             1
#define LOW            0

#define   LINE1(x)       (0x80 + x)
#define   LINE2(x)       (0xC0 + x)

#define RIGHT_SCROLL      0x1C
#define LEFT_SCROLL       0x18
#define EIGHT_BIT_MODE    0x30  // 0x0011(M) 0000
#define FOUR_BIT_MODE     0x23  // 0x0010  0011
#define TWO_LINE_8_BIT_MODE 0x38 // 0x0011 (N)10(F)00
#define CLEAR_DISPLAY       0x01
#define DISPLAY_ON          0x0E     // 0x0000 11(D)0(B)0(c))

void lcd_init(void);
static void clcd_write(unsigned char byte,unsigned char mode);
static void init_display(void);
void clcd_print(const char *str,unsigned char addr);
void lcd_right_scroll(unsigned char times);
void lcd_left_scroll(unsigned char times);

#endif	/* LCD_H */

