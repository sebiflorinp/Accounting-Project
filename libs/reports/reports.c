#include <stdio.h>
#include <time.h>
#include <string.h>
#include "../activityLog/activityLog.h"

void statements(int accountId) {
    /*
     * A function that prints all statements of the account with the received id.
     * Preconditions: accountId: the id of the account.
     * Post-conditions: -
     */
    // get current day month and year
    time_t time1;
    struct tm *currentTime;
    time1 = time(NULL);
    currentTime = localtime(&time1);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    // open the db
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    char typeDB[100];
    int count = 0;
    // go through the transaction and print those who are made from and towards the account and where made 31 days ago
     while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8)
        if ((accountId == sourceAccountIdDB || accountId == destinationAccountIdDB) && yearDB == currentYear && (currentMonth == monthDB || (currentMonth - monthDB == 1 && currentDay >= dayDB))) {
            if (destinationAccountIdDB == 0)
                printf("%d %d %s %f %d %d %d\n", idDB, sourceAccountIdDB, typeDB, valueDB, dayDB, monthDB, yearDB);
            else
                printf("%d %d %s %f %d %d %d %d\n", idDB, sourceAccountIdDB, typeDB, valueDB, destinationAccountIdDB, dayDB, monthDB, yearDB);
            count++;
        }
     if (count == 0)
         printf("There are no statements to display.\n");
     char formattedString[1000];
     sprintf(formattedString, "The statements of the account with the id of %d were requested.", accountId);
     addActivity(formattedString);
}

void balances(int userId) {
    /*
     * A function that prints the balances of all accounts of the user with the received id.
     * Preconditions: userId: an int
     * Post-conditions: -
     */
    // open the db
    FILE *accountsDB = fopen("../db/accounts.txt", "r");
    int ownerIdDB, accountIdDB;
    float balanceDB;
    char nameDB[100], typeDB[100];
    // go through all accounts and print the id, name and statement of those that are owned by the user with the received id
    int count = 0;
    while (fscanf(accountsDB, "%d %d %s %f %s", &accountIdDB, &ownerIdDB, nameDB, &balanceDB, typeDB) == 5)
        if (userId == ownerIdDB) {
            printf("%d %s %f\n", accountIdDB, nameDB, balanceDB);
            count++;
        }
    if (count == 0)
        printf("There are no accounts whose balance to display.\n");
    char formattedString[1000];
    sprintf(formattedString, "The user with the id of %d has requested their balances.", userId);
    addActivity(formattedString);
}

void transactions(int accountId) {
    /*
     * A function that prints all transactions made from and towards the account with the received id
     * Preconditions: accountId: an int
     * Post-conditions: -
     */
    // open the db
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    char typeDB[100];
    int count = 0;
    // go through the transactions and print those who are made from and towards the account and where made 31 days ago
     while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8)
        if (accountId == sourceAccountIdDB || accountId == destinationAccountIdDB) {
            if (destinationAccountIdDB == 0)
                printf("%d %d %s %f %d %d %d\n", idDB, sourceAccountIdDB, typeDB, valueDB, dayDB, monthDB, yearDB);
            else
                printf("%d %d %s %f %d %d %d %d\n", idDB, sourceAccountIdDB, typeDB, valueDB, destinationAccountIdDB, dayDB, monthDB, yearDB);
            count++;
        }
     if (count == 0)
         printf("There are no transaction to display.\n");
     char formattedString[1000];
     sprintf(formattedString, "The statements of the account with the id of %d were requested.", accountId);
     addActivity(formattedString);
}

void expenses(int accountId) {
    /*
     * A function that prints all expenses made by the account that has the received id.
     * Preconditions: accountId: an int
     * Post-conditions: -
     */
    // open the db
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    char typeDB[100];
    int count = 0;
    // go through the transactions and print the expense that are made from and towards the account with the received id
     while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8)
        if (accountId == sourceAccountIdDB && strcmp(typeDB, "Expense") == 0) {
            if (destinationAccountIdDB == 0)
                printf("%d %d %s %f %d %d %d\n", idDB, sourceAccountIdDB, typeDB, valueDB, dayDB, monthDB, yearDB);
            else
                printf("%d %d %s %f %d %d %d %d\n", idDB, sourceAccountIdDB, typeDB, valueDB, destinationAccountIdDB, dayDB, monthDB, yearDB);
            count++;
        }
     if (count == 0)
         printf("There are no expenses to display.\n");
     char formattedString[1000];
     sprintf(formattedString, "The expenses of the account with the id of %d were requested.", accountId);
     addActivity(formattedString);
}