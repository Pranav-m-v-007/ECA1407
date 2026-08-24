// Reg No: 192411030
// Name: Pranav
// Embedded System - ECA1407
#include <reg51.h>

void main()
{
    while (1)
    {
        unsigned int num1, num2;
        unsigned long int product;

        num1 = 0x2122;
        num2 = 0xBBBB;

        product = (unsigned long int)num1 * num2;

        P0 = product & 0xFF;
        P1 = (product & 0xFF00) >> 8;
        P2 = (product & 0xFF0000) >> 16;
        P3 = (product & 0xFF000000) >> 24;
    }
}
