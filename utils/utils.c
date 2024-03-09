#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void removeTrailingNewLine(char* string) {
    if (strlen(string) > 0) {
        string[strlen(string) - 1] = '\0';
    }
}

char* encrypt(char* toEncrypt) {
    int len = strlen(toEncrypt);
    char* encryptedData= malloc(sizeof(char) * len);
    strcpy(encryptedData,toEncrypt);
    for (int i = 0; i < len; i++) {
        if ('a' <= encryptedData[i] && encryptedData[i] <='z')
            encryptedData[i] = 'a' + (encryptedData[i] - 'a' + i % 26) % 26;
        if ('A' <= encryptedData[i] && encryptedData[i] <='Z')
            encryptedData[i] = 'A' + (encryptedData[i] - 'A' + i % 26) % 26;
    }
    return encryptedData;
}

void freeMemory(char* ptr) {
    memset(ptr, 0, strlen(ptr) * sizeof(char));
    free(ptr);
    ptr = 0;
}

void displayLoginInstructions() {
    printf(
           "You can do this using the following commands:\n"
           "  1. Create an account\n"
           "  2. Log in\n"
           "  3. Exit\n"
           );
}

void displayApplicationInstructions() {
    printf(
           "  1. Create financial account.\n"
           "  2. Edit financial account.\n"
           "  3. Delete financial account.\n"
           "  4. Deposit money.\n"
           "  5. Withdraw money.\n"
           "  6. Transfer money.\n"
           "  7. Print statements of an account.\n"
           "  8. Print balances.\n"
           "  9. Print transactions of an account.\n"
           "  10. Print the expenses of an account.\n"
           "  11. Add user to the list of important users.\n"
           "  12. Update an important user.\n"
           "  13. Delete an important user.\n"
           "  14. Display important users.\n"
           "  15. Logout.\n"
           );
}