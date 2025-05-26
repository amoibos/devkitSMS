#include "console.h"
#include "keyboard.h"
#include "assets.h"

#define KEY_AMOUNT          ((6))

#define INFOLINE            ((10))
#define OUTPUT_ROWS         ((KEY_AMOUNT + 1))

#define CENTER(x)           ((TEXTCONSOLE_MAX_X >> 1) - (strlen(x) >> 1))

void load_ascii_tiles(unsigned int position) {

    SG_loadTilePatterns(font__tiles__bin, position, font__tiles__bin_size);
    SG_loadTileColours(font__palette__bin, position, font__palette__bin_size); 
}

void main(void) {
    unsigned char keys_pressed, row;
    unsigned int keys[KEY_AMOUNT];
    unsigned int code;
    unsigned char output[TEXTCONSOLE_MAX_X+1];
    
    load_ascii_tiles(0);
    load_ascii_tiles(256);
    load_ascii_tiles(512);

    clear_screen();
    SG_displayOn(); 
   
    strcpy(output, "Keyboard Test");
    print_str(CENTER(output), 1, output);
    strcpy(output, "sample program: " PROG_NAME);
    print_str(CENTER(output), 3, output);
    
    while(1) {

        //reset key buffer
        for(unsigned char n=0; n < KEY_AMOUNT; n++) {
            keys[n] = 0;
        }
        
        keys_pressed = SG_getKeycodes(keys, KEY_AMOUNT);
    
        if (keys_pressed) {
            for(unsigned char y=INFOLINE; y < INFOLINE + OUTPUT_ROWS; ++y)
                clear_line(y);
            
            strcpy(output, "pressed keys: ");
            print_str(0, INFOLINE, output);
            print_num(strlen(output) + 2, INFOLINE, keys_pressed);
            
             
            for(unsigned char i=0; i < keys_pressed; ++i) {
                split_keycode(keys[i], &row, &code);
                
                print_str( 0, INFOLINE + 1 + i, "row:");
                print_num( 4, INFOLINE + 1 + i, row);
                
                print_str(6, INFOLINE + 1 + i, "code:");
                print_num(11, INFOLINE + 1 + i, code); 

                print_str(16, INFOLINE + 1 + i, "N:");
                print_num(18, INFOLINE + 1 + i, is_number(keys[i]));

                print_str(20, INFOLINE + 1 + i, "L:");
                print_num(22, INFOLINE + 1 + i, is_letter(keys[i]));

                print_str(24, INFOLINE + 1 + i, "#:");
                print_num(26, INFOLINE + 1 + i, keys[i]);
            }
        } 
        
        for(unsigned char n=0; n < 4; ++n)
            SG_waitForVBlank();  
    }
}
