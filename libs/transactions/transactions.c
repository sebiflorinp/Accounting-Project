#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../models/models.h"
#include "../activityLog/activityLog.h"

bool deposit(int ownerId, int accountId, float value) {
    /*
     * A function that adds the received value in the account with the received owner and account id
     * Preconditions: ownerId: an int
     *                accountId: an int
     *                value: a float
     * Post-conditions: a bool
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    Account accounts[1000];
    // store the accounts in an array and deposit the money in the account with the matching ids
    int count = 0;
    bool found = false;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB && accountId == accountIdDB) {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            accounts[count].balance = balanceDB + value;
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
    // return false if no account was found with the received ids
    if (!found)
        return false;
    fclose(accountsDB);
    // store the new data in the db
    accountsDB = fopen("../db/accounts.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(accountsDB, "%d %d %s %f %s\n", accounts[index].accountId, accounts[index].ownerId, accounts[index].name,
                accounts[index].balance, accounts[index].type);
    fclose(accountsDB);
    // store the transaction to the transaction DB
    // get the number of transactions
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    count = 1;
    while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8) {
        count++;
    }
    fclose(transactionsDB);
    // get the current time
    time_t time1;
    struct tm *currentTime;
    time1 = time(NULL);
    currentTime = localtime(&time1);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    // write the transaction in the db
    transactionsDB = fopen("../db/transactions.txt", "a");
    fprintf(transactionsDB, "%d %d %s %f %d %d %d %d\n", count, accountId, "Income", value, 0, currentDay, currentMonth, currentYear);
    fclose(transactionsDB);
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d deposited %f money in the account with the id of %d.", ownerId, value, accountId);
    addActivity(formattedString);
    return true;
}

bool withdraw(int ownerId, int accountId, float value) {
    /*
     * A function that withdraws money from the account with the received owner and account id.
     * Preconditions: ownerId: an int
     *                accountId: an int
     *                value: a float
     * Post-conditions: a bool
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    Account accounts[1000];
    // store the accounts in an array and withdraw the money in the account with the matching ids
    int count = 0;
    bool found = false;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB && accountId == accountIdDB) {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            // return false if the withdrawal operation cannot be performed due to trying to withdraw more money than
            // there are in the account
            if (balanceDB < value)
                return false;
            accounts[count].balance = balanceDB - value;
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
    // return false if no account was found with the received ids
    if (!found)
        return false;
    fclose(accountsDB);
    // store the new data in the db
    accountsDB = fopen("../db/accounts.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(accountsDB, "%d %d %s %f %s\n", accounts[index].accountId, accounts[index].ownerId, accounts[index].name,
                accounts[index].balance, accounts[index].type);
    fclose(accountsDB);
    // store the transaction to the transaction DB
    // get the number of transactions
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    count = 1;
    while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8) {
        count++;
    }
    fclose(transactionsDB);
    // get the current time
    time_t time1;
    struct tm *currentTime;
    time1 = time(NULL);
    currentTime = localtime(&time1);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    // write the transaction in the db
    transactionsDB = fopen("../db/transactions.txt", "a");
    fprintf(transactionsDB, "%d %d %s %f %d %d %d %d\n", count, accountId, "Expense", value, 0, currentDay, currentMonth, currentYear);
    fclose(transactionsDB);
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d withdrawn %f money from the account with the id %d", ownerId, value, accountId);
    addActivity(formattedString);
    return true;
}

bool transfer(int ownerId, int sourceAccountId, int destinationAccountId, float value) {
    /*
     * A function that transfers a certain amount of money from one account to another.
     * Preconditions: ownerId: an int
     *                sourceAccountId: an int
     *                destinationAccountId: an int
     *                value: a float
     * Post-conditions: a bool
     */
    // Check if the money is transferred to different accounts
    if (sourceAccountId == destinationAccountId)
        return false;
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    Account accounts[1000];
    // store the accounts in an array and withdraw the money in the account with the matching ids
    int count = 0;
    bool found = false;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB && sourceAccountId == accountIdDB) {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            // return false if the transaction cannot be performed if there are less money than it is transferred
            if (balanceDB < value)
                return false;
            accounts[count].balance = balanceDB - value;
            found = true;
        } else if (accountIdDB == destinationAccountId) {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            accounts[count].balance = balanceDB + value;
        } else {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            accounts[count].balance = balanceDB;
        }
        count++;
    }
    // return false if the source account was not found with the received ids
    if (!found)
        return false;
    fclose(accountsDB);
    // store the new data in the db
    accountsDB = fopen("../db/accounts.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(accountsDB, "%d %d %s %f %s\n", accounts[index].accountId, accounts[index].ownerId, accounts[index].name,
                accounts[index].balance, accounts[index].type);
    fclose(accountsDB);
    // store the transaction to the transaction DB
    // get the number of transactions
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    count = 1;
    while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8) {
        count++;
    }
    fclose(transactionsDB);
    // get the current time
    time_t time1;
    struct tm *currentTime;
    time1 = time(NULL);
    currentTime = localtime(&time1);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    // write the transaction in the db
    transactionsDB = fopen("../db/transactions.txt", "a");
    fprintf(transactionsDB, "%d %d %s %f %d %d %d %d\n", count, sourceAccountId, "Expense", value, destinationAccountId, currentDay, currentMonth, currentYear);
    fclose(transactionsDB);
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d transferred %f money from the account with the id of %d to the account with the id of %d", ownerId, value, sourceAccountId, destinationAccountId);
    addActivity(formattedString);
    return true;
}

bool payment(int ownerId, int accountId, float value) {
    /*
     * A function that makes a payment.
     * Preconditions: ownerId: an int
     *                accountId: an int
     *                value: a float
     * Post-conditions: a bool
     */
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    Account accounts[1000];
    // store the accounts in an array and deduct the money in the account with the matching ids
    int count = 0;
    bool found = false;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5) {
        if (ownerId == ownerIdDB && accountId == accountIdDB) {
            accounts[count].accountId = accountIdDB;
            accounts[count].ownerId = ownerIdDB;
            strcpy(accounts[count].type, typeDB);
            strcpy(accounts[count].name, nameDB);
            // return false if the payment operation cannot be performed due to trying to pay more money than
            // there are in the account
            if (balanceDB < value)
                return false;
            accounts[count].balance = balanceDB - value;
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
    // return false if no account was found with the received ids
    if (!found)
        return false;
    fclose(accountsDB);
    // store the new data in the db
    accountsDB = fopen("../db/accounts.txt", "w");
    for (int index = 0; index < count; index++)
        fprintf(accountsDB, "%d %d %s %f %s\n", accounts[index].accountId, accounts[index].ownerId, accounts[index].name,
                accounts[index].balance, accounts[index].type);
    fclose(accountsDB);
    // store the transaction to the transaction DB
    // get the number of transactions
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    count = 1;
    while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8) {
        count++;
    }
    fclose(transactionsDB);
    // get the current time
    time_t time1;
    struct tm *currentTime;
    time1 = time(NULL);
    currentTime = localtime(&time1);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    // write the transaction in the db
    transactionsDB = fopen("../db/transactions.txt", "a");
    fprintf(transactionsDB, "%d %d %s %f %d %d %d %d\n", count, accountId, "Expense", value, 0, currentDay, currentMonth, currentYear);
    fclose(transactionsDB);
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d made a payment with the value of %f from the account with the id of %d", ownerId, value, accountId);
    addActivity(formattedString);
    return true;
}