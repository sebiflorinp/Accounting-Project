#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "obtainData.h"
#include "../validation/validation.h"
#include "../../utils/utils.h"
#include "../accounts/accounts.h"

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

char* obtainAccountId(int loggedInUser) {
    char* accountId = malloc(sizeof(char) * 20);
    bool validAccountId = false;
    while (!validAccountId) {
        fgets(accountId, 20, stdin);
        removeTrailingNewLine(accountId);
        // if the id is invalid (as in it is not a valid integer) display a special message
        if (!validateId(accountId))
            printf("The input account id is invalid, please input a valid one.\n");
        else {
            // if the account id was not chosen from the displayed list print a message
            validAccountId = validateAccountId(loggedInUser, atoi(accountId));
            if (!validAccountId)
                printf("You do not own the account with the input id, please input the"
                       "id of an account from the list.\n");
        }
    }
    return accountId;
}

char* obtainAccountName() {
    bool validAccountName = false;
    char * accountName = malloc(sizeof(char) * 100);
    // loop that runs until a valid account name is received
    while (!validAccountName) {
        printf("Input the name of the account.\n");
        fgets(accountName, 100, stdin);
        removeTrailingNewLine(accountName);
        validAccountName = validateUsername(accountName);
        if (!validAccountName)
            printf("The account name is invalid, please input a valid one.\n");
    }
    return accountName;
}

char* obtainAccountType() {
    char *accountType  = malloc(sizeof(char) * 10);
    bool validAccountType = false;
    while (!validAccountType) {
        printf("Choose the type of the account:\n"
               "  1. Savings\n"
               "  2. Checking\n"
               "  3. Credits\n"
               );
        fgets(accountType, 10, stdin);
        removeTrailingNewLine(accountType);
        validAccountType = validateType(accountType);
        if (!validAccountType)
            printf("The chosen account type is invalid, please choose a valid one.\n");
    }
    return accountType;
}

char* obtainConfirmation() {
    char *confirmation = malloc(sizeof(char) * 10);
    bool validConfirmation = false;
    while (!validConfirmation) {
        fgets(confirmation, 10, stdin);
        removeTrailingNewLine(confirmation);
        validConfirmation = validateConfirmation(confirmation);
        if (!validConfirmation)
            printf("The input confirmation is not valid, please input a valid one.\n");
    }
    return confirmation;
}

char* obtainValue() {
    char* value = malloc(sizeof(char) * 20);
    bool validValue = false;
    while (!validValue) {
        fgets(value, 20, stdin);
        removeTrailingNewLine(value);
        validValue = validateValue(value);
        if (!validValue)
            printf("The input value is not valid, please input a valid one.\n");
    }
    return value;
}

char* obtainAccountIdToTransferTo() {
    char* accountIdToTransferTo = malloc(sizeof(char) * 20);
    bool validAccountIdToTransfer = false;
    while (!validAccountIdToTransfer) {
        fgets(accountIdToTransferTo, 20, stdin);
        removeTrailingNewLine(accountIdToTransferTo);
        // if the id is invalid (as in it is not a valid integer) display a special message
        if (!validateId(accountIdToTransferTo))
            printf("The input account id is invalid, please input a valid one.\n");
        else {
            // if the account id does not belong to any account display a special message
            validAccountIdToTransfer = checkIfAccountExists(atoi(accountIdToTransferTo));
            if (!validAccountIdToTransfer)
                printf("The input id does not belong the any account, you need to input "
                       "an id that belongs to an account.\n");
        }
    }
    return accountIdToTransferTo;
}