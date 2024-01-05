#ifndef CP2_ACCOUNTS_H
#define CP2_ACCOUNTS_H

#include <stdbool.h>

    // function that adds a financial account in the db
    bool createAccount(int ownerID, char* name, char* type);

    // function that edits a financial account in the db
    bool editAccount(int ownerId, int accountId, char* newName, char* newType);

    // function that deletes a financial account in the db
    bool deleteAccount(int ownerId, int accountId);
#endif //CP2_ACCOUNTS_H
