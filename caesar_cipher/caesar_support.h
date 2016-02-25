/* 
 * Support features for Caesar Cipher implementation. Support contains:
 *  - Argument parser:
 *      All the required logic for arguments from shell
 *  - Help message constructor:
 *      Display the help message, explaining the options and usage of the program
 *  - File reader:
 *      Read the caesar text from file
 */
#ifndef CAESAR_SUPPORT_H
#define CAESAR_SUPPORT_H

/* Readability improvements for _Bool types */
#define true 1
#define false 0
typedef _Bool bool;

/* Pre-program settings */
void display_help_message(char *program_name);

/*
 * Arguments accepted by program:
 *  - Decrypt: bool for represent if program is in encrypt or decrypt mode
 *  - File: char* for filename
 *  - Text: the input text for work with
 *  - Key: the number of shifts for/in the text
 */
void parse_arguments(int argc, char *argv[], bool *decrypt, int *key, char **text, char **file);

/* Text input related functions */
char *read_input_from_file(char *filename);
unsigned int get_length_of_text(char *text);

#endif
