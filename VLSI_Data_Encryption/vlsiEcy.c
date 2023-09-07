#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to perform XOR encryption
void encrypt(char *plaintext, char *key) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        plaintext[i] ^= key[i];
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char plaintext[101]; // Maximum length of 100 characters plus null terminator
    char key[101];       // To store the encryption key

    // Input
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the newline character from input

    // Generate a random encryption key of the same length as the plaintext
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256; // Generate a random byte (0-255)
    }
    key[length] = '\0'; // Null-terminate the key

    // Encrypt the plaintext
    encrypt(plaintext, key);

    // Display the encryption key and encrypted text
    printf("Encryption key: ");
    for (int i = 0; i < length; i++) {
        printf("0x%02X", (unsigned char)key[i]);
    }
    printf("\n");

    printf("Encrypted text: ");
    for (int i = 0; i < length; i++) {
        printf("0x%02X", (unsigned char)plaintext[i]);
    }
    printf("\n");

    return 0;
}
