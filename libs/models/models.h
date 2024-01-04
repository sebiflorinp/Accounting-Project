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
        int userId;
        int type;
        float value;
        int receiverId;
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
        int idUser1;
        // id of the user who is important
        int idUser2;
        char description[1000];
    } ImportantUser;
#endif //CP2_MODELS_H
