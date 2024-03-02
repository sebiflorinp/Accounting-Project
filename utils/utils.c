#include <string.h>
#include <malloc.h>
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
