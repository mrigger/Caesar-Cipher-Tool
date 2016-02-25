#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#define ALPHABET_SIZE 26
static const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";

/*
 * The shift function is the same for encrypt/decrypt mode
 * Decrypt for a key of 10 is equal the encryption with a key of (alphabet size - key)
 */
char *apply_shift_to_text(char *text, int text_length, int shift_value);

#endif
