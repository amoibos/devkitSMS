#include "console.h"

void clear_line(unsigned char line) {
	for(int x=0; x < TEXTCONSOLE_MAX_X; ++x) {
    	SG_setTileatXY(x, line, ' ');
	}  
}

void clear_screen(void) {
    for(int y=0; y < TEXTCONSOLE_MAX_Y; ++y)
    	clear_line(y);    
}

void print_str(unsigned char x, unsigned char y, char *str) {
    for(; *str; ++str) {
        if (x >= 32)
            ++y, x=0;
        SG_setTileatXY(x++, y, *str);
    }
}

void print_num(unsigned char x, unsigned char y, long num) {
    char buffer[10+1]; 
    char *str; 

    str = buffer;
    SEGA_itoa(num, buffer);
    
    for(; *str; ++str) {
        if (x >= 32)
            ++y, x=0;
        SG_setTileatXY(x++, y, *str);
    }
}
