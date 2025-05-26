#include "strings.h"

unsigned char* SEGA_itoa(long value, unsigned char * sp) {
    long q, r;
    unsigned char *start;
    unsigned char t, sign = value < 0;
    unsigned char *dest = sp;

    start = sp;

    if (sign)
        value *= -1;

    do {
        q = value / 10;
        r = value % 10;

        if (q)
            value /= 10;
        else
            value -= r;

        *sp++ = '0' + r;
    } while(value);
    if (sign)
        *sp++ = '-';

    *sp-- = '\0';


    while(start < sp) {
        t = *start;
        *start++ = *sp;
        *sp-- = t;
    }
    return dest;
}



unsigned char strlen(const unsigned char * str) {
    const unsigned char *s;

    for (s = str; *s; ++s) ;

    return s - str;
}

unsigned char* strcpy(unsigned char* dest, const unsigned char* src) {
    unsigned char* rdest=dest;

    while(*dest++ = *src++);

    return rdest;
}
