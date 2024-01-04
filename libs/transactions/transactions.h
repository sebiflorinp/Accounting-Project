#include <stdbool.h>

#ifndef CP2_TRANSACTIONS_H
#define CP2_TRANSACTIONS_H
    // a function that deposits money
    bool deposit(int ownerId, int accountId, float value);

    // a function that withdraws money
    bool withdraw(int ownerId, int accountId, float value);

    // a function that transfer money from one account to another
    bool transfer(int ownerId, int accountIdSource, int accountIdDestination, float value);

    // a function that makes a payment
    bool payment(int ownerId, int accountId, float value);
#endif //CP2_TRANSACTIONS_H
