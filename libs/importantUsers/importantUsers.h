#ifndef CP2_IMPORTANTUSERS_H
#define CP2_IMPORTANTUSERS_H

#include <stdbool.h>

    // a function that adds an important user in the db
    bool addUser(int currentUserId, int importantUserId, char description[]);

    // a function that edits an important user from the db
    bool editUser(int currentUserId, int importantUserId, char newDescription[]);

    // a function that deletes an important user from the db
    bool deleteUser(int currentUserId, int importantUserId);

    // a function that prints all important users of a certain user
    void displayImportantUsers(int currentUserId);
#endif //CP2_IMPORTANTUSERS_H
