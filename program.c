#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "coolsdk/cool.h"

void encrypt() {
    printf("Type the message to encrypt: ");
    
    char input[9001];
    scanf(" %9000[^\n]", input);
    int len = strlen(input);

    printf("Type numeric key code to encrypt with: ");
    
    int key;
    scanf("%d", &key);

    char* output = coolStringEncrypt(input, key, len);

    printHexString(output, len);
    free(output);
}

void decrypt() {
    printf("Type the message to decrypt: ");
    
    char input[9001];
    scanf(" %9000[^\n]", input);
    int len = strlen(input);

    printf("Type numeric key code to decrypt with: ");
    
    int key;
    scanf("%d", &key);

    char* newInput = parseHexString(input, len);
    len /= 2;

    char* output = coolStringDecrypt(newInput, key, len);
    printf("%s\n", output);

    free(newInput);
    free(output);
}

int main() {
    printf("Welcome to my cool encryptor program!\n");

    while (true) {
        printf("Encrypt (0), decrypt (1), or exit (2)?\n");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            encrypt();
        } else if (choice == 1) {
            decrypt();
        } else if (choice == 2) {
            printf("Goodbye!");
            break;
        }
    }
}