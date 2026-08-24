#include <reg51.h>

void main(void)
{
    unsigned char hexa = 0XCFH;
    unsigned char hundreds, tens, units;

    ACC = hexa;
    B = 10;
    ACC = ACC / B;
    units = B;

    B = 10;
    ACC = ACC / B;
    tens = B;

    hundreds = ACC;

    P0 = units;
    P1 = tens;
    P2 = hundreds;

    while(1);
}