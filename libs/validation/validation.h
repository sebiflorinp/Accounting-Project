#ifndef CP2_VALIDATION_H
#define CP2_VALIDATION_H

#include <stdbool.h>
    // id validator
    bool validateId(char* id);

    // validate account id
    bool validateAccountId(int userId, int accountId);

    // action validator
    bool validateActionLoginMenu(char* action);
    bool validateActionMenu(char* action);

    // username validator
    bool validateUsername(char* username);

    // password validator
    bool validatePassword(char* password);

    // value validator
    bool validateValue(char* value);

    // type validator
    bool validateType(char* type);

    // confirmation validator
    bool validateConfirmation(char* confirmation);

    // validate the description of an important user
    bool validateDescription(char *description);
#endif //CP2_VALIDATION_H
