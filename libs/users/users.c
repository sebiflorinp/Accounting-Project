#include "users.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../libs/activityLog/activityLog.h"
#include "../../utils/utils.h"

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
    // encrypt password
    strcpy(password, encrypt(password));
    // if there is no other users with the received username add the new user and return true
    usersDB = fopen("../db/users.txt", "a");
    fprintf(usersDB,"%d %s %s\n", counter, username, password);
    fclose(usersDB);
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d the username %s and the encrypted password %s was created.", counter, username, password);
    addActivity(formattedString);
    return true;
}

int logInUser(char *username, char* password) {
    /*
     * A function that checks if the username and password are correct and returns a result
     * Preconditions: username: a char array
     *                password: a char array
     * Post-conditions: an integer
     */
    // open db
    FILE *usersDB;
    usersDB = fopen("../db/users.txt", "r");
    // encrypt the password
    strcpy(password, encrypt(password));
    // declare id, username and password for data from the db
    int idDB;
    char usernameDB[200], passwordDB[200];
    // check if there is any user with the same username as the input one and then check the passwords, if they match return true
    while (fscanf(usersDB, "%d %s %s", &idDB, usernameDB, passwordDB) == 3) {
        if (strcmp(username, usernameDB) == 0)
            if (strcmp(password, passwordDB) == 0) {
                char formatedString[1000];
                sprintf(formatedString, "The user with the id of %d logged in.", idDB);
                addActivity(formatedString);
                return idDB;
            }
    }
    fclose(usersDB);
    //return false if the passwords do not match or if there isn't any user with the input username
    return 0;
}

void logOutUser(int loggedInUserId) {
    /*
     * A function that logs out the user (mostly used for the activity log)
     * Preconditions: loggedInUserId: an int
     * Post-conditions: -
     */
    char formatedString[1000];
    sprintf(formatedString, "The user with the id of %d logged out.", loggedInUserId);
    addActivity(formatedString);
}

bool checkIfUserExists(int id) {
    /*
     * A function that checks if the user with the input id exists in the db
     * Preconditions: id: an integer
     * Post-conditions: a bool
     */
    // open db
    FILE *usersDB;
    usersDB = fopen("../db/users.txt", "r");
    // declare id, username and password for data from the db
    int idDB;
    char usernameDB[200], passwordDB[200];
    // return true if a user with the received id is read from the db
    while (fscanf(usersDB, "%d %s %s", &idDB, usernameDB, passwordDB) == 3) {
        if (idDB == id)
            return true;
    }
    // return false if the user wasn't found
    return false;
}