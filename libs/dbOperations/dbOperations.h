#ifndef ACCOUNT_PROJECT_DBOPERATIONS_H
#define ACCOUNT_PROJECT_DBOPERATIONS_H

#include "../models/models.h"


int loadUsers(User* users);

void saveUsers(User* users, int numberOfUsers);

int loadTransactions(Transaction* transactions);

void saveTransactions(Transaction* transactions, int numberOfTransactions);

int loadAccounts(Account* accounts);

void saveAccounts(Account* accounts, int numberOfAccounts);


#endif //ACCOUNT_PROJECT_DBOPERATIONS_H

