#include <stdio.h>
#include "dbOperations.h"

int loadUsers(User* users) {
    FILE *usersDB;
    usersDB = fopen("../db/users.txt", "r");
    int numberOfUsers = 0;
    while (fscanf(
            usersDB,
            "%d %s %s",
            &users[numberOfUsers].id,
            users[numberOfUsers].username,
            users[numberOfUsers].password
            ) == 3) {
        numberOfUsers++;
    }
    fclose(usersDB);
    return numberOfUsers;
}

void saveUsers(User* users, int numberOfUsers) {
    FILE* usersDB = fopen("../db/users.txt", "w");
    for (int i = 0; i < numberOfUsers; i++)
        fprintf(usersDB,
                "%d %s %s\n",
                users[i].id,
                users[i].username,
                users[i].password
                );
    fclose(usersDB);
}

int loadTransactions(Transaction* transactions) {
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int numberOfTransactions = 0;
    while (fscanf(
            transactionsDB,
            "%d %d %s %f %d %d %d %d",
            &transactions[numberOfTransactions].id,
            &transactions[numberOfTransactions].sourceAccountId,
            transactions[numberOfTransactions].type,
            &transactions[numberOfTransactions].value,
            &transactions[numberOfTransactions].destinationAccountId,
            &transactions[numberOfTransactions].day,
            &transactions[numberOfTransactions].month,
            &transactions[numberOfTransactions].year
            ) == 8) {
        numberOfTransactions++;
    }
    fclose(transactionsDB);
    return numberOfTransactions;
}

void saveTransactions(Transaction* transactions, int numberOfTransactions) {
    FILE* transactionsDB = fopen("../db/transactions.txt", "w");
    for (int i = 0; i < numberOfTransactions; i++)
        fprintf(
                transactionsDB,
                "%d %d %s %f %d %d %d %d\n",
                transactions[i].id,
                transactions[i].sourceAccountId,
                transactions[i].type,
                transactions[i].value,
                transactions[i].destinationAccountId,
                transactions[i].day,
                transactions[i].month,
                transactions[i].year
                );
    fclose(transactionsDB);
}

int loadAccounts(Account* accounts) {
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int numberOfAccounts = 0;
    while (fscanf(
            accountsDB,
            "%d %d %s %f %s",
            &accounts[numberOfAccounts].accountId,
            &accounts[numberOfAccounts].ownerId,
            accounts[numberOfAccounts].name,
            &accounts[numberOfAccounts].balance,
            accounts[numberOfAccounts].type
                  ) == 5) {
        numberOfAccounts++;
    }
    fclose(accountsDB);
    return numberOfAccounts;
}

void saveAccounts(Account* accounts, int numberOfAccounts) {
    FILE* accountsDB = fopen("../db/accounts.txt", "w");
    for (int i = 0; i < numberOfAccounts; i++)
        fprintf(
                accountsDB,
                "%d %d %s %f %s\n",
                accounts[i].accountId,
                accounts[i].ownerId,
                accounts[i].name,
                accounts[i].balance,
                accounts[i].type
                );
    fclose(accountsDB);
}

int loadImportantUsers(ImportantUser* importantUsers) {
    FILE* importantUsersDB = fopen("../db/importantUsers.txt", "r");
    int numberOfImportantUsers = 0;
    while (fscanf(
            importantUsersDB,
            "%d %d %d %s %s",
            &importantUsers[numberOfImportantUsers].id,
            &importantUsers[numberOfImportantUsers].currentUserId,
            &importantUsers[numberOfImportantUsers].importantUserId,
            importantUsers[numberOfImportantUsers].importantUserName,
            importantUsers[numberOfImportantUsers].description
            ) == 5) {
        numberOfImportantUsers++;
    }
    fclose(importantUsersDB);
    return numberOfImportantUsers;
}

void saveImportantUsers(ImportantUser* importantUsers, int numberOfImportantUsers) {
    FILE* importantUsersDB = fopen("../db/importantUsers.txt", "w");
    for (int i = 0; i < numberOfImportantUsers; i++)
        fprintf(
                importantUsersDB,
                "%d %d %d %s %s\n",
                importantUsers[i].id,
                importantUsers[i].currentUserId,
                importantUsers[i].importantUserId,
                importantUsers[i].importantUserName,
                importantUsers[i].description
                );
    fclose(importantUsersDB);
}

