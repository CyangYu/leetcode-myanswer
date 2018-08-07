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

void test(int *a)
{
    free(a);
}

int main(void)
{
    /*int u;
    byte a, b, c, d;
    char sa[3], sb[3], sc[3], sd[3];

    scanf("%d", &u);
    byte *k = (byte *)&u;
    a = k[0];
    b = k[1];
    c = k[2];
    d = k[3];

    chToHex(a, sa);
    chToHex(b, sb);
    chToHex(c, sc);
    chToHex(d, sd);
    printf("%s\n", k);
    printf("%s %s %s %s\n", sa, sb, sc, sd);
    */

    int *a = (int *)malloc(sizeof(int));
    *a = 100;
    printf("%p %d\n", a, *a);

    test(a);
    printf("%p %d\n", a, *a);
    a = nullptr;
    return 0;    
}
