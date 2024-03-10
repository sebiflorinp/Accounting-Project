#ifndef CP2_ACCOUNTS_H
#define CP2_ACCOUNTS_H

#include <stdbool.h>
#include "../models/models.h"

    // function that adds a financial account in the db
    bool createAccount(int ownerID, char* name, char* type);

    // function that edits a financial account in the db
    bool editAccount(int ownerId, int accountId, char* newName, char* newType);

    // function that deletes a financial account in the db
    bool deleteAccount(int ownerId, int accountId);
    // function that displays the accounts of an user
    bool displayAccounts(int ownerId);

    // a function that returns the number of accounts of a certain user
    int returnNumberOfAccounts(int ownerId);

    // a function that checks if an account with a certain id exists
    bool checkIfAccountExists(int id);
#endif //CP2_ACCOUNTS_H
