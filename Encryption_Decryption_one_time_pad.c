#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LEN 100

void generateKey(int key[], int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26;
    }
}

void encrypt(char plain[], int key[], char cipher[], int len) {
    for (int i = 0; i < len; i++) {
        if (isupper(plain[i])) {
            cipher[i] = (plain[i] - 'A' + key[i]) % 26 + 'A';
        } else if (islower(plain[i])) {
            cipher[i] = (plain[i] - 'a' + key[i]) % 26 + 'a';
        } else if (isdigit(plain[i])) {
            cipher[i] = (plain[i] - '0' + key[i]) % 10 + '0';
        } else {
            cipher[i] = plain[i];
        }
    }
}

void decrypt(char cipher[], int key[], char plain[], int len) {
    for (int i = 0; i < len; i++) {
        if (isupper(cipher[i])) {
            plain[i] = (cipher[i] - 'A' - key[i] + 26) % 26 + 'A';
        } else if (islower(cipher[i])) {
            plain[i] = (cipher[i] - 'a' - key[i] + 26) % 26 + 'a';
        } else if (isdigit(cipher[i])) {
            plain[i] = (cipher[i] - '0' - key[i] + 10) % 10 + '0';
        } else {
            plain[i] = cipher[i];
        }
    }
}

int main() {
    char plain[MAX_LEN + 1], cipher[MAX_LEN + 1], decrypted[MAX_LEN + 1];
    int key[MAX_LEN], len;

    printf("Enter a message to encrypt (max length %d): ", MAX_LEN);
    fgets(plain, MAX_LEN + 1, stdin);

    len = strlen(plain) - 1;

    generateKey(key, len);

    encrypt(plain, key, cipher, len);

    printf("Original message: %s\n", plain);
    printf("Encrypted message: %s\n", cipher);

    decrypt(cipher, key, decrypted, len);

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}

