#include <stdio.h>
#include <string.h>
#include "importantUsers.h"
#include "../models/models.h"

bool addUser(int currentUserId, int importantUserId, char description[]) {
    /*
     * A function that adds an user to the important list of another user.
     * Preconditions: currentUserId: an int
     *                importantUserId: an int
     *                description: a char array
     * Post-conditions: a bool
     */
    // return false if the currentUser and the importantUser is the same
    if (currentUserId == importantUserId)
        return false;
    // get the id of the following entry
    // open db
    FILE* importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int idDB, currentUserIdDB, importantUserIdDB;
    char importantUserNameDB[2000], descriptionDB[2000];
    int maxId = 0;
    while (fscanf(importantUsersDB, "%d %d %d %s %s", &idDB, &currentUserIdDB, &importantUserIdDB, importantUserNameDB, descriptionDB) == 5) {
        if (maxId < importantUserIdDB)
            maxId = importantUserIdDB;
        // if that important user is already in the db return false
        if (currentUserIdDB == currentUserId && importantUserId == importantUserIdDB)
            return false;
    }
    fclose(importantUsersDB);
    // check if the user id exists and if it is find the name of the new important user.
    char importantUserName[2000] = " ";
    char usernameDB[2000], passwordDB[2000];
    FILE* usersDB = fopen("../db/users.txt", "r");
    while (fscanf(usersDB, "%d %s %s", &idDB, usernameDB, passwordDB) == 3) {
        if (importantUserId == idDB)
            strcpy(importantUserName, usernameDB);
    }
    fclose(usersDB);
    // if the username was not found due to not finding the id return false
    if (strcmp(importantUserName, " ") == 0)
        return false;
    //parse description to turn spaces into underlines.
    char stringToBeModified[2000];
    strcpy(stringToBeModified, description);
    char *pointer = strtok(stringToBeModified, " ");
    char parsedDescription[2000] = "";
    while (pointer != NULL) {
        strcat(parsedDescription, pointer);
        strcat(parsedDescription, "_");
        pointer = strtok(NULL, " ");
    }
    // add the new entry in the db
    importantUsersDB = fopen("../db/importantUsers.txt", "a");
    fprintf(importantUsersDB, "%d %d %d %s %s\n", maxId + 1, currentUserId, importantUserId, importantUserName, parsedDescription);
    fclose(importantUsersDB);
    return true;
}
bool editUser(int currentUserId, int importantUserId, char newDescription[]) {
    /*
     * A function that edits the important user whose id matches
     * Preconditions: currentUserId: an int
     *                importantUserId: an int
     *                newDescription: a char array
     * Post-conditions: a bool
     */
    // check if the important user is in the db and edit it and store the users in an array
    // open db
    FILE *importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int idDB, currentUserIdDB, importantUserIdDB;
    char usernameDB[2000], descriptionDB[2000];
    ImportantUser importantUsers[1000];
    int count = 0;
    bool found = false;
    while (fscanf(importantUsersDB, "%d %d %d %s %s", &idDB, &currentUserIdDB, &importantUserIdDB, usernameDB, descriptionDB) == 5) {
        if (currentUserIdDB == currentUserId && importantUserId == importantUserIdDB) {
            importantUsers[count].id = idDB;
            importantUsers[count].currentUserId = currentUserIdDB;
            importantUsers[count].importantUserId = importantUserIdDB;
            strcpy(importantUsers[count].importantUserName, usernameDB);
            //parse description to turn spaces into underlines.
            char stringToBeModified[2000];
            strcpy(stringToBeModified, newDescription);
            char *pointer = strtok(stringToBeModified, " ");
            char parsedDescription[2000] = "";
            while (pointer != NULL) {
                strcat(parsedDescription, pointer);
                strcat(parsedDescription, "_");
                pointer = strtok(NULL, " ");
            }
            strcpy(importantUsers[count].description, parsedDescription);
            found = true;
        } else {
            importantUsers[count].id = idDB;
            importantUsers[count].currentUserId = currentUserIdDB;
            importantUsers[count].importantUserId = importantUserIdDB;
            strcpy(importantUsers[count].importantUserName, usernameDB);
            strcpy(importantUsers[count].description, descriptionDB);
        }
        count++;
    }
    fclose(importantUsersDB);
    // if the user wasn't found return false
    if (!found)
        return false;
    // write the data from the array in the db
    importantUsersDB = fopen("../db/importantUsers.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(importantUsersDB, "%d %d %d %s %s\n", importantUsers[index].id, importantUsers[index].currentUserId,
                importantUsers[index].importantUserId, importantUsers[index].importantUserName, importantUsers[index].description);
    fclose(importantUsersDB);
    return true;
}

bool deleteUser(int currentUserId, int importantUserId) {
    /*
     * A function that deletes the important user with the received id from the list of the user with the received id
     * Preconditions: currentUserId: an int
     *                importantUserId: an int
     * Post-conditions: a bool
     */
    // check if the important user is in the db and store all the other users in an array
    // open db
    FILE *importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int idDB, currentUserIdDB, importantUserIdDB;
    char usernameDB[2000], descriptionDB[2000];
    ImportantUser importantUsers[1000];
    int count = 0;
    bool found = false;
    while (fscanf(importantUsersDB, "%d %d %d %s %s", &idDB, &currentUserIdDB, &importantUserIdDB, usernameDB, descriptionDB) == 5) {
        if (currentUserIdDB == currentUserId && importantUserId == importantUserIdDB) {
            found = true;
        } else {
            importantUsers[count].id = idDB;
            importantUsers[count].currentUserId = currentUserIdDB;
            importantUsers[count].importantUserId = importantUserIdDB;
            strcpy(importantUsers[count].importantUserName, usernameDB);
            strcpy(importantUsers[count].description, descriptionDB);
            count++;
        }
    }
    fclose(importantUsersDB);
     // if the user wasn't found return false
    if (!found)
        return false;
    // write the data from the array in the db
    importantUsersDB = fopen("../db/importantUsers.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(importantUsersDB, "%d %d %d %s %s\n", importantUsers[index].id, importantUsers[index].currentUserId,
                importantUsers[index].importantUserId, importantUsers[index].importantUserName, importantUsers[index].description);
    fclose(importantUsersDB);
    return true;
}
void displayImportantUsers(int currentUserId) {
    /*
     * A function that displays all important users of the user with the received id
     * Preconditions: currentUserId
     * Post-conditions: -
     */
    // print all users that are important to the user with the received id or print a special message if there aren't any
    // open db
    FILE *importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int idDB, currentUserIdDB, importantUserIdDB;
    char usernameDB[2000], descriptionDB[2000];
    int count = 0;
    while (fscanf(importantUsersDB, "%d %d %d %s %s", &idDB, &currentUserIdDB, &importantUserIdDB, usernameDB, descriptionDB) == 5)
        if (currentUserIdDB == currentUserId) {
            //parse description to turn spaces into underlines.
            char stringToBeModified[2000];
            strcpy(stringToBeModified, descriptionDB);
            char *pointer = strtok(stringToBeModified, "_");
            char parsedDescription[2000] = "";
            while (pointer != NULL) {
                strcat(parsedDescription, pointer);
                strcat(parsedDescription, " ");
                pointer = strtok(NULL, "_");
            }
            printf("%d %d %d %s %s\n", idDB, currentUserIdDB, importantUserIdDB, usernameDB, parsedDescription);
            count++;
        }
    fclose(importantUsersDB);
    if (count == 0)
        printf("There are no important users.\n");
}

bool checkImportantUser(int userId, int importantUserId) {
    /*
     * A function that checks if an user has another user as an important user
     * Preconditions: userId: an int
     *                importantUser: an int
     * Post-conditions: a bool
     */
    // open db
    FILE *importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int idDB, currentUserIdDB, importantUserIdDB;
    char usernameDB[2000], descriptionDB[2000];
    // check if the ids match
    while (fscanf(importantUsersDB, "%d %d %d %s %s", &idDB, &currentUserIdDB, &importantUserIdDB, usernameDB, descriptionDB) == 5)
        if (currentUserIdDB == userId && importantUserIdDB == importantUserId)
            return true;
    fclose(importantUsersDB);
    // return false if the ids didn't match
    return false;
}


bool checkIfUserHasImportantUsers(int userId) {
    /*
     * A function that checks if a certain user has any important users
     * Preconditions: userId: an int
     * Post-conditions: a bool
     */
    // open db
    FILE *importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int idDB, currentUserIdDB, importantUserIdDB;
    char usernameDB[2000], descriptionDB[2000];
    int count = 0;
    // count the users
    while (fscanf(importantUsersDB, "%d %d %d %s %s", &idDB, &currentUserIdDB, &importantUserIdDB, usernameDB, descriptionDB) == 5)
        if (currentUserIdDB == userId)
            count++;
    fclose(importantUsersDB);
    if (count == 0)
        return false;
    else
        return true;
}
