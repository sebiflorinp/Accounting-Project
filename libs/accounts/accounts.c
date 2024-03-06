#include "accounts.h"
#include "../models/models.h"
#include "../activityLog/activityLog.h"
#include "../dbOperations/dbOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool createAccount(int ownerID, char* name, char* type, Account* accounts, int numberOfAccounts) {
    /*
     * A function that attempts to add a new entry in the accounts db and returns a bool depending on the result
     * Preconditions: ownerID: am int
     *                name: a char array
     *                type: an int
     */
    // check if there is already an account owned by the logged in user with the same name
    for (int i = 0; i < numberOfAccounts; i++)
        if (strcmp(accounts[i].name, name) == 0 && ownerID == accounts[i].ownerId)
            return false;
    // find the maxId
    int maxId = 0;
    for (int i = 0; i < numberOfAccounts; i++)
        if (accounts[i].accountId > maxId)
            maxId = accounts[i].accountId;
    // Add the account if the user doesn't have one with the same name
    accounts = realloc(accounts, numberOfAccounts + 1);
    accounts[numberOfAccounts].accountId = maxId + 1;
    accounts[numberOfAccounts].ownerId = ownerID;
    strcpy(accounts[numberOfAccounts].name, name);
    strcpy(accounts[numberOfAccounts].type, type);
    accounts[numberOfAccounts].balance = 0;
    saveAccounts(accounts, numberOfAccounts + 1);
    char formattedString[1000];
    sprintf(
            formattedString,
            "The user with the id of %d has created the account with the id of %d, name of %s and type of %s.",
            accounts[numberOfAccounts].accountId,
            accounts[numberOfAccounts].ownerId,
            accounts[numberOfAccounts].name,
            accounts[numberOfAccounts].type
            );
    addActivity(formattedString);
    return true;
}

bool editAccount(int ownerId, int accountId, char* newName, char* newType, Account* accounts, int numberOfAccounts) {
    /*
     * A function that edits the account with the given id of the user with the given id
     * Preconditions: ownerId: an int
     *                accountId: an int
     *                newName: a string
     *                newType: an int
     * Post-conditions: a bool
     */
    bool found = false;
    // edit the accounts
    for (int i = 0; i < numberOfAccounts; i++)
        if (ownerId == accounts[i].ownerId && accountId == accounts[i].accountId) {
            found = true;
            strcpy(accounts[i].name, newName);
            strcpy(accounts[i].type, newType);
        }
    // return false if no account was edited
    if (!found)
        return false;
    // store the new data in the db
    saveAccounts(accounts, numberOfAccounts);
    char formattedString[1000];
    sprintf(
            formattedString,
            "The user with the id of %d edited the account with the id of %d with the new name of %s and type of %s.",
            ownerId,
            accountId,
            newName,
            newType
            );
    addActivity(formattedString);
    return true;
}

bool deleteAccount(int ownerId, int accountId) {
    /*
     * A function that deletes the account that has the received owner and account id.
     * Preconditions: ownerId: an int
     *                accountId: an int
     * Post-conditions: a bool
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    Account accounts[1000];
    // store the accounts in an array except the one that has to be deleted
    int count = 0;
    bool found = false;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB && accountId == accountIdDB) {
            found = true;
        }
        else {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            accounts[count].balance = balanceDB;
            count++;
        }
    }
    // return false if no account was deleted
    if (!found)
        return false;
    fclose(accountsDB);
    // store the new data in the db
    accountsDB = fopen("../db/accounts.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(accountsDB, "%d %d %s %f %s\n", accounts[index].accountId, accounts[index].ownerId, accounts[index].name,
                accounts[index].balance, accounts[index].type);
    fclose(accountsDB);
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d deleted the account with the id of %d.", ownerId, accountId);
    addActivity(formattedString);
    return true;
}

bool displayAccounts(int ownerId) {
    // open db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    // Display the accounts
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerIdDB == ownerId)
            printf("%d %s %f %s\n", accountIdDB, nameDB, balanceDB, typeDB);
    }
    // close db
    fclose(accountsDB);
}

int returnNumberOfAccounts(int ownerId) {
    /*
     * A function that returns the number of accounts owned by the user with the received id.
     * Preconditions: ownerId: an int
     * Post-conditions: an int
     */
    // open db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    int count = 0;
    // Count the accounts
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB)
            count++;
    }
    // close db
    fclose(accountsDB);
    // return the number of accounts
    return count;
}

bool checkIfAccountExists(int id) {
    /*
     * A function that checks if an account with the received id exists.
     * Preconditions: id: an int
     * Post-conditions: a bool
     */
    // open db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    // go through the accounts
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        // return true if the account was found
        if (accountIdDB == id)
            return true;
    }
    // close db
    fclose(accountsDB);
    // return false if no account was found.
    return false;
}