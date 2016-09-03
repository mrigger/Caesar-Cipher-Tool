#include<stdio.h>
#include<ctype.h>

#include"caesar_support.h"
#include"caesar_cipher.h"

int main(int argc, char *argv[])
{
    bool decrypt = false;
    char *file = "", *text = "";
    int key = 0, text_length = 0;

    parse_arguments(argc, argv, &decrypt, &key, &text, &file);

    text_length = get_length_of_text(text);

    for (char *textPtr = text; *textPtr; ++textPtr) {
        *textPtr = tolower(*textPtr); 
    }

    /* 
     * Setting the key:
     * As the algorithm does not operate in inverse mode, the decryption key is the same as alphabet size - key;
     */
    if (decrypt && key != 0) {
        key = ALPHABET_SIZE - key;
        printf("%s\n", apply_shift_to_text(text, text_length, key));
        return 0;
    }
    
    /* Attempt brute force on text */
    if (decrypt && key == 0) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            printf("Key %d:\t%s\n", (ALPHABET_SIZE - i), apply_shift_to_text(text, text_length, i));
        } 

        return 0;
    }

    printf("%s\n", apply_shift_to_text(text, text_length, key));

    return 0;
}
