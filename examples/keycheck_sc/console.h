#ifndef CONSOLE_H
#define CONSOLE_H

#include "SGlib.h"

#include "strings.h"

#define TEXTCONSOLE_MAX_Y       ((24))
#define TEXTCONSOLE_MAX_X       ((32))

void clear_line(unsigned char line);
void clear_screen(void);

void print_str(unsigned char x, unsigned char y, char *str);
void print_num(unsigned char x, unsigned char y, long num);

#endif

