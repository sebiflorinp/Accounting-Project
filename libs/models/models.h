#ifndef CP2_MODELS_H
#define CP2_MODELS_H
    // user model
    typedef struct {
       int id;
       char username[200];
       char password[200];
    } User;

    // transaction model
    typedef struct {
        int id;
        int sourceAccountId;
        char type[40];
        float value;
        int destinationAccountId;
        int day;
        int month;
        int year;
    } Transaction;

    // Account model
    typedef struct {
        int accountId;
        int ownerId;
        char name[200];
        float balance;
        char type[200];
    } Account;

    // important user model
    typedef struct {
        int id;
        // id of the user to whom is another user important
        int currentUserId;
        // id of the user who is important
        int importantUserId;
        char importantUserName[2000];
        char description[2000];
    } ImportantUser;
#endif //CP2_MODELS_H
