#include <xc.h>
#include "i2c.h"
#include "ds1307.h"

void init_eeprom(void)
{
    unsigned char dummy;
   
    dummy = read_eeprom(SEC_ADDR);
    dummy = dummy & 0x7F;
    write_eeprom(SEC_ADDR, dummy);// ch = 0
}

unsigned char read_eeprom(unsigned char addr)
{
    unsigned char data;
    
    i2c_start();
    i2c_write(SLAVE_WRITE);
    i2c_write(addr);
    i2c_rep_start();
    i2c_write(SLAVE_READ);
    data = i2c_read(0);
    i2c_stop();
    
    return data;
}

void write_eeprom(unsigned char addr, unsigned char data) // SEc_ADDR, data
{
    i2c_start();
    i2c_write(SLAVE_WRITE);
    i2c_write(addr);
    i2c_write(data);
    i2c_stop();
}
