#include <stdio.h>
#include "libs/users/users.h"
#include "libs/accounts/accounts.h"
#include "libs/transactions/transactions.h"
#include "libs/reports/reports.h"
#include "libs/validation/validation.h"
#include <time.h>
#include <string.h>
#include "libs/importantUsers/importantUsers.h"
#include <stdbool.h>
#include <stdlib.h>

int main() {
    // global variables
    bool running = true;
    int loggedInUser = 0;
    char username[2000], password[2000], passwordAgain[2000], action[2000] = "";
    // application loop
    while (running) {
        // print login menu instruction
        printf("In order to use this application you need to create an account and log in.\nYou can do this using "
               "the following commands:\n  1. Create an account\n  2. Log in\n  3. Exit\n");
        // log in menu loop
        while (!loggedInUser) {
            // conditions to meet when making a new account
            bool validUsername = false;
            bool validPassword = false;
            bool passwordsMatch = false;
            // the user chooses an action
            printf("Select an action:\n");
            scanf("%s", action);
            // check if the action is valid
            if (validateActionLoginMenu(action)) {
                switch (atoi(action)) {
                    // create a new account option
                    case 1:
                        printf("Input the username.\n");
                        // the loop asks for an username until it receives a valid one
                        while (!validUsername) {
                            scanf("%s", username);
                            validUsername = validateUsername(username);
                            if (!validUsername)
                                printf("The input username is invalid, please input a valid one.\n");
                        }
                        printf("Input the password.\n");
                        // the loop asks for a password until it receives a valid one and is input a second time properly
                        while (!validPassword || !passwordsMatch) {
                            while (!validPassword) {
                                scanf("%s", password);
                                validPassword = validatePassword(password);
                                if (!validPassword)
                                    printf("The password is invalid, please input a valid one.\n");
                            }
                            printf("Input the password again.\n");
                            scanf("%s", passwordAgain);
                            passwordsMatch = strcmp(password, passwordAgain) == 0;
                            if (!passwordsMatch) {
                                 printf("The passwords do not match, please input the passwords again.\n");
                                 validPassword = false;
                            }
                        }
                        printf("The account was created successfully.\n");
                        createUser(username, password);
                        break;
                    // log in option
                    case 2:
                        // the user is asked to input their username and password
                        printf("Input the username.\n");
                        scanf("%s", username);
                        printf("Input the password.\n");
                        scanf("%s", password);
                        // loggedInUser has the id of the logged user or 0 if the data wasn't good
                        loggedInUser = logInUser(username, password);
                        if (loggedInUser == 0)
                            printf("The username or the password were wrong!\n");
                        else
                            printf("You have logged in successfully.\n");
                        break;
                        // exit option
                    case 3:
                        running = false;
                        printf("Thank you for using this application!\n");
                        loggedInUser = 1;
                        break;
                }

            } else {
                printf("The was not a valid action, please choose a valid one!\n");
            }

        }

    }
    }

