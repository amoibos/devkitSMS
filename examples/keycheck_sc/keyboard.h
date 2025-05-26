#ifndef KEYBOARD_H
#define KEYBOARD_H

// deconstruct keycode to get pressed key and row
void split_keycode(unsigned int combined, unsigned char *row, unsigned int *code);
_Bool is_number(unsigned int keycode);
_Bool is_letter(unsigned int keycode);

#endif
