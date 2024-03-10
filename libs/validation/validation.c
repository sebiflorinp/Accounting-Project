#include "validation.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool validateId(char* id) {
    /*
     * A function that checks if the received id is valid.
     * Preconditions: id: a char array
     * Post-conditions: a bool
     */
    // Check if the id is only made of numbers, if it isn't return false
    for (int index = 0; index < strlen(id); index++)
        if (!('0' <= id[index] && id[index] <= '9'))
            return false;
    // If the id is made only of numbers return true
    return true;
}

bool validateAccountId(int userId, int accountId) {
    /*
     * A function that checks if the account with the received id is owned by the user with the received id.
     * Preconditions: userId: an int
     *                accountId: an int
     * Preconditions: a bool
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    // go throw accounts and find if there is an account that has the received ids
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (accountIdDB == accountId && ownerIdDB == userId)
            return true;
    }
    // close db
    fclose(accountsDB);
    // return false if there was no account that has the received ids
    return false;
}

bool validateActionLoginMenu(char* action) {
    /*
     * A function that checks if the received action is valid.
     * Preconditions: action: a char array
     * Post-conditions: a bool
     */
    // Check if the action is only made of numbers
    for (int index = 0; index < strlen(action); index++)
        if (!('0' <= action[index] && action[index] <= '9'))
            return false;
    // Check if action if between 1 and 3
    if (!(1 <= atoi(action) && atoi(action) <= 3))
        return false;
    // If the id is made only of numbers return true
    return true;

}

bool validateActionMenu(char* action) {
    /*
     * A function that checks if the received action is valid.
     * Preconditions: action: a char array
     * Post-conditions: a bool
     */
    // Check if the action is only made of numbers
    for (int index = 0; index < strlen(action); index++)
        if (!('0' <= action[index] && action[index] <= '9'))
            return false;
    // Check if action if between 1 and 20
    if (!(1 <= atoi(action) && atoi(action) <= 15))
        return false;
    // If the id is made only of numbers return true
    return true;

}


bool validateUsername(char* username) {
    /*
     * A function that checks if the received username is valid.
     * Preconditions: username: a char array
     * Post-conditions: a bool
     */
    // Check if the length of the username is at least 4, if it isn't return false
    if (strlen(username) < 4)
        return false;
    // Check if the username is only made of letters and numbers, if it isn't return false
    for (int index = 0; index < strlen(username); index++)
        if (!(('a' <= username[index] && username[index] <= 'z') || ('A' <= username[index] && username[index] <= 'Z') || ('0' <= username[index] && username[index] <= '9')))
            return false;
    // If the username is only made of letters and numbers and is at least 4 characters long return true
    return true;
}

bool validatePassword(char* password) {
    /*
     * A function that checks if the received password is valid.
     * Preconditions: password: a char array
     * Post-conditions: a bool
     */
    // Check if the length of the password is at least 4 characters long, if it isn't return false
    if (strlen(password) < 4)
        return false;
    // Check if the password is only made of characters and numbers, if it isn't return false
    for (int index = 0; index < strlen(password); index++)
        if (!(('a' <= password[index] && password[index] <= 'z') || ('A' <= password[index] && password[index] <= 'Z') || ('0' <= password[index] && password[index] <= '9')))
            return false;
    // If the password is only made of letters and numbers and is at least 4 characters long return true;
    return true;
}

bool validateValue(char* value) {
    /*
     * A function that checks if the received value is valid.
     * Preconditions: value: a char array
     * Post-conditions: a bool
     */
    // Check if the value contains only numbers and '.' which is used for floats
    for (int index = 0; index < strlen(value); index++)
        if (!(('0' <= value[index] && value[index] <= '9') || value[index] == '.'))
            return false;
    // If the value is made only of numbers and '.' return true
    return true;
}

bool validateType(char* type) {
    /*
     * A function that checks if the received type is valid.
     * Preconditions: type: a char array
     * Post-conditions: a bool
     */
    // Check if the type is of length 1, if it isn't return false
    if (strlen(type) != 1)
        return false;
    // Check if the type is 1, 2 or 3, if it isn't return false
    if (type[0] != '1' && type[0] != '2' && type[0] != '3')
        return false;
    // If the type is 1, 2 or 3 return true
    return true;
}

bool validateConfirmation(char* confirmation) {
    /*
     * A function that check if the received confirmation is valid.
     * Preconditions: confirmation: a string
     * Post-conditions: a bool
     */
    // check if the confirmation is 1 character long
    if (strlen(confirmation) != 1)
        return false;
    // check if the confirmation is y or n
    if (confirmation[0] != 'y' && confirmation[0] != 'n')
        return false;
    return true;
}

bool validateDescription(char *description) {
    /*
     * A function that checks if the received description is valid.
     * Preconditions: description: a char array
     * Post-conditions: a bool
     */
    // check if the description is at least 4 characters long
    if (strlen(description) < 4)
        return false;
    // check if the description contains only numbers, letters and spaces
    for (int index = 0; index < strlen(description); index++)
        if (!(('0' <= description[index] && description[index] <= '9') || ('a' <= description[index] && description[index] <='z') || ('A' <=description[index] && description[index] <='Z') || description[index] == ' '))
            return false;
    return true;
}

