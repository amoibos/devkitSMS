#include "keyboard.h"

// deconstruct keycode to get pressed key and row
void split_keycode(unsigned int combined, unsigned char *row, unsigned int *code) {
  
  *row = combined >> 12; 
  *code = combined & 0x0FFF;
}

_Bool is_number(unsigned int keycode) {
    unsigned char row;
    unsigned short kc_row;
    
    split_keycode(keycode, &row, &kc_row);

    return  (
                (row <= 6) && (kc_row == 1)
            ) ||
            (
                (row <= 2) && (kc_row == 256)
            );
}

_Bool is_letter(unsigned int keycode) {
    unsigned char row;
    unsigned short kc_row;
    
    split_keycode(keycode, &row, &kc_row);

    return  (
                (row <= 6) && ((kc_row >= 2) && (kc_row <= 8))
            ) ||
            (
                (row <= 2) && (kc_row >= 64) && (keycode != 0x0240)
            );
}
