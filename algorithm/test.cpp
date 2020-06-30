#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

#define sw16(x) \
    ((short)(\
    (((short)(x) & (short)0x00ffU) << 8) | \
    (((short)(x) & (short)0xff00U) >> 8)))

void chToHex(byte val, char *dest)
{
    byte temp = val % 16;
    if (temp >= 0 && temp <= 9)
        dest[1] = '0' + temp;
    else if (temp >= 10 && temp <= 15)
        dest[1] = 'A' + temp - 10;
    
    temp = (val / 16) % 16;
    if (temp >= 0 && temp <= 9)
        dest[0] = '0' + temp;
    else if (temp >= 10 && temp <= 15)
        dest[0] = 'A' + temp - 10;
    
    dest[2] = '\0';
}
