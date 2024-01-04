#include <stdio.h>
#include "libs/dbInteraction/users/users.h"
#include "libs/dbInteraction/accounts/accounts.h"
#include "libs/transactions/transactions.h"
#include <time.h>

int main() {
    deposit(1, 1, 5);
    deposit(1, 1, 5);
    deposit(2, 3, 20);
    withdraw(1, 1, 2);
    transfer(1, 1, 3, 5);
    return 0;
}
