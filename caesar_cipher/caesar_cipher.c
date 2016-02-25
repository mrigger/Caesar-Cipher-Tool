#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "caesar_cipher.h"

char *apply_shift_to_text(char *text, int text_length, int shift_value){
    char *final_text = malloc(sizeof(char) * text_length);

    for(int i = 0; i < text_length; i++){
        if(isspace(text[i])){
            final_text[i] = ' ';
            continue; 
        }
        final_text[i] = ALPHABET[((text[i] - 'a') + shift_value) % ALPHABET_SIZE];
    }

    return final_text;
}
