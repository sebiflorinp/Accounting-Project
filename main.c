#include <stdio.h>
#include "libs/users/users.h"
#include "libs/accounts/accounts.h"
#include "libs/transactions/transactions.h"
#include "libs/reports/reports.h"
#include "libs/validation/validation.h"
#include <string.h>
#include "libs/importantUsers/importantUsers.h"
#include <stdbool.h>
#include <stdlib.h>
#include "libs/obtainData/obtainData.h"
#include "utils/utils.h"
#include "libs/models/models.h"
#include "libs/dbOperations/dbOperations.h"

int main() {
    // global variables
    bool running = true;
    bool loggedIn = false;
    int loggedInUser = 0;
    char *username;
    char *password;
    char *action;
    // load users
    User *users = malloc(sizeof(User) * 1000);
    int numberOfUsers = loadUsers(users);
    users = realloc(users, numberOfUsers);
    // load accounts
    Account *accounts = malloc(sizeof(Account) * 1000);
    int numberOfAccounts = loadAccounts(accounts);
    accounts = realloc(accounts, numberOfAccounts);
    // load transactions
    Transaction *transactions = malloc(sizeof(Transaction) * 1000);
    int numberOfTransactions = loadTransactions(transactions);
    transactions = realloc(transactions, numberOfTransactions);
    // load important users
    ImportantUser *importantUsers = malloc(sizeof(ImportantUser) * 1000);
    int numberOfImportantUsers = loadImportantUsers(importantUsers);
    importantUsers = realloc(importantUsers, numberOfImportantUsers);
    // application loop
    printf("In order to use this application you need to create an account and login.\n");
    while (running) {
        // print login menu instruction
        displayLoginInstructions();
        // log in menu loop
        while (!loggedIn && running) {
            // the user chooses an action
            printf("Select an action:\n");
            action = malloc(sizeof(char) * 10);
            fgets(action, 10, stdin);
            removeTrailingNewLine(action);
            // check if the action is valid
            if (validateActionLoginMenu(action)) {
                switch (atoi(action)) {
                    // create a new account option
                    case 1:
                        username = obtainUsername();
                        password = obtainPassword();
                        if (createUser(username, password, users, numberOfUsers)) {
                            printf("The account was created successfully.\n");
                            numberOfUsers++;
                        } else
                            printf("There is already an account with the input username\n");
                        freeMemory(username);
                        freeMemory(password);
                        break;
                        // log in option
                    case 2:
                        // the user is asked to input their username and password
                        printf("Input the username.\n");
                        username = malloc(sizeof(char) * 100);
                        fgets(username, 100, stdin);
                        removeTrailingNewLine(username);
                        printf("Input the password.\n");
                        password = malloc(sizeof(char) * 100);
                        fgets(password, 100, stdin);
                        removeTrailingNewLine(password);
                        // loggedInUser has the id of the logged user or 0 if the data wasn't good
                        loggedInUser = logInUser(username, password);
                        if (loggedInUser == 0)
                            printf("The username or the password were wrong!\n");
                        else {
                            loggedIn = true;
                            printf("You have logged in successfully.\n");
                        }
                        freeMemory(username);
                        freeMemory(password);
                        break;
                        // exit option
                    case 3:
                        running = false;
                        printf("Thank you for using this application!\n");
                        loggedInUser = 0;
                        break;
                }
                printf("Press ENTER key to continue\n");
                getchar();
            } else {
                printf("The was not a valid action, please choose a valid one!\n");
                printf("Press ENTER key to continue\n");
                getchar();
                printf("In order to interact with this application you need to choose one of the following commands:\n");
            }

        }
        // print instructions
        if (running) {
            printf("In this application you can manage different financial accounts.\n");
            // application menu loop
            while (loggedIn && running) {
                displayApplicationInstructions();
                // needed variables
                char *accountName;
                char *accountType;
                char *accountId;
                char *confirmationMessage;
                char *confirmation;
                char *value;
                char *accountIdToTransferTo;
                char userId[200], description[2000], importantUsername[2000];
                bool validAccountName = false, validAccountType = false, validValue = false, validDescription = false, validImportantUsername = false;
                bool validAccountId = false, validConfirmation = false, validAccountIdToTransfer = false, validUserId = false;
                printf("Select an action:\n");
                fgets(action, 10, stdin);
                removeTrailingNewLine(action);
                if (validateActionMenu(action)) {
                    switch (atoi(action)) {
                        // financial account creation
                        case 1:
                            accountName = obtainAccountName();
                            accountType = obtainAccountType();
                            // Check if the account name is already used and give a proper response.
                            if (createAccount(loggedInUser, accountName, accountType)) {
                                printf("The account was created successfully.\n");
                                numberOfAccounts++;
                            } else
                                printf("There is already an account that uses the input name\n");
                            free(accountName);
                            free(accountType);
                            break;
                            // edit financial account
                        case 2:
                            // if the logged in user doesn't have any account show a special message
                            if (returnNumberOfAccounts(loggedInUser) == 0)
                                printf("In order to edit an account you need to create one, please create one before"
                                       " trying to edit it.\n");
                            else {
                                printf("Input the ID of the financial account that will be edited:\n");
                                displayAccounts(loggedInUser);
                                accountId = obtainAccountId(loggedInUser);
                                printf("Enter the new name of the account\n");
                                accountName = obtainAccountName();
                                accountType = obtainAccountType();
                                // Check if the update can be done,
                                if (editAccount(loggedInUser, atoi(accountId), accountName, accountType))
                                    printf("The account was updated successfully.\n");
                                else
                                    printf("The input name is already used by another account used by you.\n");
                                free(accountId);
                                free(accountName);
                                free(accountType);
                            }
                            break;
                            // delete account function
                        case 3:
                            // if the logged in user doesn't have any account show a special message
                            if (returnNumberOfAccounts(loggedInUser) == 0)
                                printf("In order to delete an account you need to create one, please create one before"
                                       " trying to delete it.\n");
                            else {
                                printf("Input the ID of the financial account that will be deleted:\n");
                                displayAccounts(loggedInUser);
                                accountId = obtainAccountId(loggedInUser);
                                // ask for confirmation before deleting the account
                                printf("Do you want to delete selected financial account? (y/n)\n");
                                confirmation = obtainConfirmation();
                                // display a message depending on the confirmation
                                if (strcmp(confirmation, "y") == 0) {
                                    deleteAccount(loggedInUser, atoi(accountId));
                                    printf("The account was deleted successfully.\n");
                                } else
                                    printf("The account with the input id was not deleted.\n");
                                free(accountId);
                                free(confirmation);
                            }
                            break;
                            // deposit money
                        case 4:
                            // if the user does not have any account display a special message
                            if (returnNumberOfAccounts(loggedInUser) == 0)
                                printf("In order to deposit money into an account you need to create one, please "
                                       "create one before trying to deposit money into it.\n");
                            else {
                                printf("Input the id of the account in which the money will be deposited.\n");
                                displayAccounts(loggedInUser);
                                accountId = obtainAccountId(loggedInUser);
                                printf("Input the amount of money that will be deposited.\n");
                                value = obtainValue();
                                // deposit the money and notify the user
                                deposit(loggedInUser, atoi(accountId), atof(value));
                                printf("The deposit was made successfully!\n");
                            }
                            break;
                            // withdraw money
                        case 5:
                            // if the user does not have any account display a special message
                            if (returnNumberOfAccounts(loggedInUser) == 0)
                                printf("In order to withdraw money from an account you need to create one, please "
                                       "create one before trying to withdraw money from it.\n");
                            else {
                                printf("Input the id of the account from which the money will be withdrawn.\n");
                                displayAccounts(loggedInUser);
                                accountId = obtainAccountId(loggedInUser);
                                printf("Input the amount of money that will be withdrawn.\n");
                                value = obtainValue();
                                // withdraw the money and notify the user
                                if (withdraw(loggedInUser, atoi(accountId), atof(value)))
                                    printf("The withdrawal was made successfully!\n");
                                else
                                    printf("The withdrawal was unsuccessful, you can not withdraw more money then are"
                                           " in the account.\n");
                                free(accountId);
                                free(value);
                            }
                            break;
                            // transfer money
                        case 6:
                            // if the user does not have any account display a special message
                            if (returnNumberOfAccounts(loggedInUser) == 0)
                                printf("In order to transfer money from an account to another you need to create one, please "
                                       "create one before trying to transfer money from it to another.\n");
                            else {
                                printf("Input the id of the account from which the money will be transferred.\n");
                                displayAccounts(loggedInUser);
                                accountId = obtainAccountId(loggedInUser);
                                printf("Input the id of the account to which to money will be transferred.\n");
                                accountIdToTransferTo = obtainAccountIdToTransferTo();
                                if (atoi(accountIdToTransferTo) == atoi(accountId)) {
                                    printf("You cannot transfer money to the same account.\n");
                                } else {
                                    printf("Input the amount of money that will be transferred.\n");
                                    value = obtainValue();
                                    printf("Do you want to transfer %f to the account with the id of %d? (y/n)\n",
                                        atof(value), atoi(accountIdToTransferTo));
                                    confirmation = obtainConfirmation();
                                    // transfer the money and notify the user depending on the results
                                    if (strcmp(confirmation, "y") == 0)
                                        if (transfer(loggedInUser, atoi(accountId), atoi(accountIdToTransferTo),
                                                     atof(value)))
                                            printf("The transfer was successful!\n");
                                        else
                                            printf("You cannot transfer more money than it is in your account.\n");
                                    else
                                        printf("The transfer was cancelled.\n");
                                    free(accountId);
                                    free(accountIdToTransferTo);
                                    free(value);
                                    free(confirmation);
                                }
                            }
                            break;
                            // display statements
                        case 7:
                            printf("Input the id of the account:\n");
                            displayAccounts(loggedInUser);
                            accountId = obtainAccountId(loggedInUser);
                            // print all statements
                            printf("Statements:\n");
                            statements(atoi(accountId));
                            free(accountId);
                            break;
                            // print balances feature
                        case 8:
                            // print balances
                            printf("Balances:\n");
                            balances(loggedInUser);
                            break;
                            // display transactions
                        case 9:
                            printf("Input the id of the account:\n");
                            displayAccounts(loggedInUser);
                            accountId = obtainAccountId(loggedInUser);
                            // displaying the transactions
                            displayTransactions(atoi(accountId));
                            free(accountId);
                            break;
                            //display the expenses of an account
                        case 10:
                            printf("Input the id of the account:\n");
                            displayAccounts(loggedInUser);
                            accountId = obtainAccountId(loggedInUser);
                            // displaying the expenses
                            expenses(atoi(accountId));
                            free(accountId);
                            break;
                            // adding important user
                        case 11:
                            validUserId = false;
                            validDescription = false;
                            printf("Input the id of the important user.\n");
                            // get user id
                            while (!validUserId) {
                                scanf("%s", userId);
                                // if the id is invalid (as in it is not a valid integer) display a special message
                                if (!validateId(userId))
                                    printf("The input account id is invalid, please input a valid one.\n");
                                else {
                                    // if the user id does not exist display a message
                                    validUserId = checkIfUserExists(atoi(userId));
                                    if (!validUserId)
                                        printf("The input id does not belong to any user, please input an id that belongs to an user.\n");
                                    // if the id of the user that is logged in is input display a message
                                    if (atoi(userId) == loggedInUser) {
                                        printf("The input id belongs to your account, please input another id.\n");
                                        validUserId = false;
                                    }
                                }
                            }
                            // get description
                            printf("Input a description for the important user.\n");
                            while (!validDescription) {
                                getchar();
                                fgets(description, 2000, stdin);
                                description[strlen(description) - 1] = 0;
                                validDescription = validateDescription(description);
                                if (!validDescription)
                                    printf("The input description is not valid, please input a valid one.\n");
                            }
                            // add important user
                            if (addUser(loggedInUser, atoi(userId), description))
                                printf("The user was added successfully in the list of important users!\n");
                            else
                                printf("The chosen user is already in the list of important users.\n");
                            break;
                            // edit important user
                        case 12:
                            // if the logged in user doesn't have any important users return a message
                            if (!checkIfUserHasImportantUsers(loggedInUser))
                                printf("In order to edit an important user you need to add one, please add one before"
                                       " trying to edit it.\n");
                            else {
                                // prepare variables for input loops
                                validUserId = false;
                                validDescription = false;
                                printf("Input the id of the important user that will be edited:\n");
                                displayImportantUsers(loggedInUser);
                                // choosing a user loop
                                while (!validUserId) {
                                    scanf("%s", userId);
                                    // if the id is invalid (as in it is not a valid integer) display a special message
                                    if (!validateId(userId))
                                        printf("The input user id is invalid, please input a valid one.\n");
                                    else {
                                        // if the user id was not chosen from the displayed list print a message
                                        validUserId = checkImportantUser(loggedInUser, atoi(userId));
                                        if (!validUserId)
                                            printf("You do not have the user with the input id as an important user,"
                                                   " please input the id of another important user.\n");
                                    }
                                }
                                printf("Input the new description of the important user.\n");
                                // choosing new description loop
                                while (!validDescription) {
                                    getchar();
                                    fgets(description, 2000, stdin);
                                    description[strlen(description) - 1] = 0;
                                    validDescription = validateDescription(description);
                                    if (!validDescription)
                                        printf("The input description is invalid, please input another one.\n");
                                }
                                editUser(loggedInUser, validUserId, description);
                                printf("The user was updated successfully!\n");
                            }
                            break;
                            // delete important user
                        case 13:
                            if (!checkIfUserHasImportantUsers(loggedInUser))
                                printf("In order to delete an important user you need to add one, please add one before"
                                       " trying to delete it.\n");
                            else {
                                // prepare variables for input loops
                                validUserId = false;
                                validConfirmation = false;
                                printf("Input the id of the important user that will be deleted:\n");
                                displayImportantUsers(loggedInUser);
                                // choosing an account loop
                                while (!validUserId) {
                                    scanf("%s", userId);
                                    // if the id is invalid (as in it is not a valid integer) display a special message
                                    if (!validateId(userId))
                                        printf("The input user id is invalid, please input a valid one.\n");
                                    else {
                                        // if the account id was not chosen from the displayed list print a message
                                        validUserId = checkImportantUser(loggedInUser, atoi(userId));
                                        if (!validUserId)
                                            printf("You do not have the user with the input id as an important user,"
                                                   " please input the id of another important user.\n");
                                    }
                                }
                                // ask for confirmation before deleting the important user
                                printf("Do you want to delete the selected important user? (y/n)\n");
                                while (!validConfirmation) {
                                    scanf("%s", confirmation);
                                    validConfirmation = validateConfirmation(confirmation);
                                    if (!validConfirmation)
                                        printf("The input confirmation is not valid, please input a valid one.\n");
                                }
                                // display a message depending on the confirmation
                                if (strcmp(confirmation, "y") == 0) {
                                    deleteUser(loggedInUser, atoi(userId));
                                    printf("The user was deleted successfully from the list of important users.\n");
                                } else
                                    printf("The important user with the input id was not deleted.\n");
                            }
                            break;
                            // display important users
                        case 14:
                            displayImportantUsers(loggedInUser);
                            break;
                            // log out
                        case 15:
                            logOutUser(loggedInUser);
                            loggedInUser = 0;
                            loggedIn = false;
                            break;
                    }
                    printf("Press ENTER key to continue\n");
                    getchar();
                } else {
                    printf("The was not a valid action, please choose a valid one!\n");
                    printf("Press ENTER key to continue\n");
                    getchar();
                }
            }
        }
    }
}