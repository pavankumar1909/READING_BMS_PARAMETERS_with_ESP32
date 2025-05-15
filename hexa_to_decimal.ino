#include "hexa_to_decimal.hpp"

int hex_to_dec_singleByte(unsigned char value,bool significance_of_byte,short int nibbles_to_format)
{
    int msn=0,lsn=0,decimal=0;
    short int byte_order=nibbles_to_format-1;
    msn=(value>>4);
    msn*=pow(16,byte_order);
    lsn=((value&0x0f));
    lsn*=pow(16,byte_order-1);
    if(significance_of_byte == true)
    {
        if(value==0xff)
          decimal= -pow(2,8); //making msb -ve if all bits are high
        else
          decimal=msn+lsn;
    }
    else 
      decimal=msn+lsn;
    return decimal;
}