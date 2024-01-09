#include <stdbool.h>

#ifndef CP2_USERS_H
#define CP2_USERS_H
    // user creator function
    bool createUser(char* username, char* password);

    // Log in function
    int logInUser(char *username, char* password);

    // check if user exists
    bool checkIfUserExists(int id);

    // a function that logs out the user
    void logOutUser(int loggedInUserId);
#endif //CP2_USERS_H
