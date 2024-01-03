#include <stdio.h>
#include "libs/dbInteraction/users/users.h"

int main() {
    char username[100] = "aaaa";
    char password[100] = "fsdfdf";
    printf("%b",logInUser(username, password));
    return 0;
}
