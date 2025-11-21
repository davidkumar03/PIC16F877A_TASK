/* 
 * File:   ds1307.h
 */

#ifndef DS1307_H
#define	DS1307_H

#define SLAVE_WRITE             0b10100000 // 0xA0
#define SLAVE_READ              0b10100001 // 0xA1

#define SEC_ADDR                0x00



void init_eeprom(void);
unsigned char read_eeprom(unsigned char addr);
void write_eeprom(unsigned char addr, unsigned char data);

#endif	/* DS1307_H */

