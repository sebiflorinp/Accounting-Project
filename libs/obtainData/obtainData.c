#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "obtainData.h"
#include "../validation/validation.h"
#include "../../utils/utils.h"

char* obtainUsername() {
    bool validUsername = false;
    char * username  = malloc(sizeof(char) * 100);
    printf("Input the username.\n");
    // the loop asks for an username until it receives a valid one
    while (!validUsername) {
        fgets(username, 100, stdin);
        removeTrailingNewLine(username);
        validUsername = validateUsername(username);
        if (!validUsername)
            printf("The input username is invalid, please input a valid one.\n");
    }
    return username;
}

char *obtainPassword() {
    bool validPassword = false;
    bool passwordsMatch = false;
    char *password = malloc(sizeof(char) * 100);
    char *passwordAgain = malloc(sizeof(char) * 100);
    printf("Input the password.\n");
    // the loop asks for a password until it receives a valid one and is input a second time properly
    while (!validPassword || !passwordsMatch) {
        while (!validPassword) {
            fgets(password, 100, stdin);
            removeTrailingNewLine(password);
            validPassword = validatePassword(password);
            if (!validPassword)
                printf("The password is invalid, please input a valid one.\n");
        }
        printf("Input the password again.\n");
        fgets(passwordAgain, 100, stdin);
        removeTrailingNewLine(passwordAgain);
        passwordsMatch = strcmp(password, passwordAgain) == 0;
        if (!passwordsMatch) {
            printf("The passwords do not match, please input the passwords again.\n");
            validPassword = false;
        }
    }
    free(passwordAgain);
    return password;
}