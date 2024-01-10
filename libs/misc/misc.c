#include <stdio.h>
#include <string.h>
#include "misc.h"

float balance(int accountId) {
    /*
     * A function that returns the balance of an account based on the transactions of that account.
     * Preconditions: accountId: an int
     * Post-conditions: a float
     */
    // open db
    float balance = 0.0f;
    FILE* transactionsDB = fopen("../db/transactions.txt", "r");
    int idDB, sourceAccountIdDB, destinationAccountIdDB, dayDB, monthDB, yearDB;
    float valueDB;
    char typeDB[100];
    // go through transactions and if the transaction is made by the account with the input id modify the balance
    while (fscanf(transactionsDB, "%d %d %s %f %d %d %d %d", &idDB, &sourceAccountIdDB, typeDB, &valueDB, &destinationAccountIdDB, &dayDB, &monthDB, &yearDB) == 8) {
        if (sourceAccountIdDB == accountId)
            if (strcmp(typeDB, "Income") == 0)
                balance += valueDB;
            else
                balance -= valueDB;
        if (destinationAccountIdDB == accountId)
            balance += valueDB;
    }
    fclose(transactionsDB);
    return balance;
}