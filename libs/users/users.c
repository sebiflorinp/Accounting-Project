#include "users.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool createUser(char* username, char* password) {
    /*
     * A function that adds a new user in the users table and returns true or returns false if the operation cannot be performed
     * Preconditions: username: a char array
     *                password: a char array
     * Post-conditions: a bool
     */
    // open db
    FILE *usersDB;
    usersDB = fopen("../db/users.txt", "r");
    // declare id, username and password for data from the db
    int idDB;
    char usernameDB[200], passwordDB[200];
    int counter = 1;
    // check if there is any other user with the same username as the input one return false if there aren't any
    while (fscanf(usersDB, "%d %s %s", &idDB, usernameDB, passwordDB) == 3) {
        if (strcmp(username, usernameDB) == 0)
            return false;
        counter++;
    }
    fclose(usersDB);
    // if there is no other users with the received username add the new user and return true
    usersDB = fopen("../db/users.txt", "a");
    fprintf(usersDB,"%d %s %s\n", counter, username, password);
    fclose(usersDB);
    return true;
}

int logInUser(char *username, char* password) {

    // open db
    FILE *usersDB;
    usersDB = fopen("../db/users.txt", "r");
    // declare id, username and password for data from the db
    int idDB;
    char usernameDB[200], passwordDB[200];
    // check if there is any user with the same username as the input one and then check the passwords, if they match return true
    while (fscanf(usersDB, "%d %s %s", &idDB, usernameDB, passwordDB) == 3) {
        if (strcmp(username, usernameDB) == 0)
            if (strcmp(password, passwordDB) == 0)
                return idDB;
    }
    fclose(usersDB);
    //return false if the passwords do not match or if there isn't any user with the input username
    return 0;
}