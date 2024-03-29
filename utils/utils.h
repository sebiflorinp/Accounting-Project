#ifndef ACCOUNT_PROJECT_UTILS_H
#define ACCOUNT_PROJECT_UTILS_H

void removeTrailingNewLine(char* string);

char* encrypt(char* toEncrypt);

char* parseText(char* toParse);

void freeMemory(char* ptr);

void displayLoginInstructions();

void displayApplicationInstructions();

#endif //ACCOUNT_PROJECT_UTILS_H
