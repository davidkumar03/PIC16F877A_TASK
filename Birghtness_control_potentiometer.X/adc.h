/* 
 * File:   adc.h
 */

#ifndef ADC_H
#define	ADC_H
#define CHANNEL0        0x00  //0b000 AN0
#define CHANNEL1        0x01 //0b001  AN1
#define CHANNEL2        0x02 //0b010  AN2
#define CHANNEL3        0x03 //0b011  AN3
#define CHANNEL5        0x05
#define CHANNEL7        0x07 //0b111  AN7

void init_adc(void);
unsigned short read_adc(unsigned char channel);

#endif	/* ADC_H */

