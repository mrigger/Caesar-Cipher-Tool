#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"caesar_support.h"

/* Pre-program settings */
void parse_arguments(int argc, char *argv[], bool *decrypt, int *key, char **text, char **file)
{
    /* The program needs to have at least 2 args: ./program [text] */
    if(argc < 2){
        display_help_message(argv[0]);
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            display_help_message(argv[0]); 
            exit(0);
        }

        if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--decrypt") == 0) {
            *decrypt = true; 
            continue;
        }

        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            if (argv[i + 1] != NULL) {
                *file = argv[i + 1]; 
                i++;
                continue;
            } else {
                printf("::Error: Incorrect usage - Filename must be specified\nSee: [-h] [--help] for help\n"); 
                exit(1);
            }
        }

        if (strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "--key") == 0) {
            if (argv[i + 1] != NULL) {
                if (atoi(argv[i + 1]) != 0) {
                    *key = atoi(argv[i + 1]); 
                    i++;
                    continue;
                } else {
                    printf("::Error: Incorrect usage - Key must be an integer value\nSee: [-h] [--help] for help\n"); 
                    exit(1);
                }
            } else {
                printf("::Error: Incorrect usage - Key must be specified\nSee: [-h] [--help] for help\n");
                exit(1);
            }
        }
        
        if (strcmp(*text, "") == 0) { 
            *text = argv[i];
            continue;
        }

        printf("::Error: Unknow argument\nSee: [-h] [--help] for help\n");
        exit(1);
    } 

    if (strcmp(*text, "") == 0 && strcmp(*file, "") == 0) {
        printf("::Error: Incorrect usage - Input text or file input must be specified\nSee: [-h] [--help] for help\n"); 
        exit(1);
    } else if (strcmp(*text, "") != 0 && strcmp(*file, "") != 0) {
        printf("::Error: Incorrect usage - Text input must be specified as argument OR as file\nSee: [-h] [--help] for help\n");
        exit(1); 
    }

    if (!*decrypt && *key == 0) {
        printf("::Error: Incorrect usage - Key is required for encrypt mode [-k] [--key]\nSee: [-h] [--help] for help\n");
        exit(1);
    }

    /* After all checks, parse the file content to text */
    if (strcmp(*file, "") != 0) {
        *text = read_input_from_file(*file); 
    }
}

void display_help_message(char *program_name) {
    printf("Usage:\n");
    printf("\nWith direct text: %s [text] [-k or --key KEY]\n\n\tor\n\nWith file as input: %s [-f or --file] [filename] [-k or --key KEY]\n", program_name, program_name);
    printf("\n[text]: string with the text to work on\n[-f or --file] [filename]: the file path to read the text\n");
    printf("[-k or --key] [KEY]: Key value [required for encrypt mode], if not specified the program will run in bruteforce mode\n");
    printf("[-d or --decrypt]: Try to decrypt instead of encrypt\n");
    printf("[-h or --help]: displays this help message\n");
}

/* Text input related functions */
char *read_input_from_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    char *file_content;

    if (file != NULL) {
        if (fseek(file, 0L, SEEK_END) == 0) {
            long bufsize = ftell(file);

            if (bufsize == -1) {
                printf("::Error: File read failed\n"); 
                exit(1);
            }

            file_content = malloc(sizeof(char) * (bufsize + 1));

            if (fseek(file, 0L, SEEK_SET) != 0) {
                printf("::Error: File read failed\n"); 
                exit(1);
            }

            size_t newLen = fread(file_content, sizeof(char), bufsize, file);
            if (newLen == 0) {
                printf("::Error: File read failed\n"); 
                exit(1);
            } else {
                file_content[++newLen] = '\0'; 
            }
        } 

        fclose(file);
    } else {
        printf("::Error: File does not exist, please specify a valid file\n");
        exit(1);
    }

    return file_content;
}

unsigned int get_length_of_text(char *text)
{
    int i = 0;
    while (text[i] != '\0') {
        i++; 
    }
    return i;
}
