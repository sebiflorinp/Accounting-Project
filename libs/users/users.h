#include <stdbool.h>

#ifndef CP2_USERS_H
#define CP2_USERS_H
    // user creator function
    bool createUser(char* username, char* password);

    // Log in function
    bool logInUser(char *username, char* password);
#endif //CP2_USERS_H
