#include "accounts.h"
#include "../models/models.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool createAccount(int ownerID, char* name, char* type) {
    /*
     * A function that attempts to add a new entry in the accounts db and returns a bool depending on the result
     * Preconditions: ownerID: am int
     *                name: a char array
     *                type: an int
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    int accounts = 1;
    // Checks if the user already has an account with the same name as the received one
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerID == ownerIdDB && strcmp(name, nameDB) == 0)
            return false;
        accounts++;
    }
    fclose(accountsDB);
    // Add the account if the user doesn't have one with the same name
    accountsDB = fopen("../db/accounts.txt", "a");
    // Add the account
    fprintf(accountsDB, "%d %d %s %f %s\n", accounts, ownerID, name, 0.0, type);
    fclose(accountsDB);
    return true;
}

bool editAccount(int ownerId, int accountId, char* newName, char* newType) {
    /*
     * A function that edits the account with the given id of the user with the given id
     * Preconditions: ownerId: an int
     *                accountId: an int
     *                newName: a string
     *                newType: an int
     * Post-conditions: a bool
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    Account accounts[1000];
    // store the accounts in an array and edit the account with the matching ids
    int count = 0;
    bool found = false;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB && accountId == accountIdDB) {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, newType);
            strcpy(accounts[count].name, newName);
            accounts[count].balance = balanceDB;
            found = true;
        } else {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            accounts[count].balance = balanceDB;
        }
        count++;
    }
    // return false if no account was edited
    if (!found)
        return false;
    fclose(accountsDB);
    // store the new data in the db
    accountsDB = fopen("../db/accounts.txt", "w");
    for (int index = 0; index <= count; index++)
        fprintf(accountsDB, "%d %d %s %f %s\n", accounts[index].accountId, accounts[index].ownerId, accounts[index].name,
                accounts[index].balance, accounts[index].type);
    fclose(accountsDB);
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
    return true;
}