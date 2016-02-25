#!/bin/bash

PROGRAM_NAME="caesar"
DEFAULT_BIN_DIRECTORY="/usr/local/bin"

# Starting 'install' process
echo "--> Compiling source code..."
gcc -o $PROGRAM_NAME caesar_cipher/main.c caesar_cipher/caesar_cipher.c caesar_cipher/caesar_support.c
echo "--> Copying program to $DEFAULT_BIN_DIRECTORY"
mv $PROGRAM_NAME $DEFAULT_BIN_DIRECTORY
if [ $? -ne 0 ]; then
    echo "::Error: Aborting..."
    exit 1
fi
echo "--> Successfully installed"
