cmake_minimum_required(VERSION 3.27)
project(Account-Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Accounting-Project main.c
        libs/validation/validation.h
        libs/validation/validation.c
        libs/users/users.h
        libs/models/models.h
        libs/users/users.c
        libs/accounts/accounts.h
        libs/accounts/accounts.c
        libs/transactions/transactions.h
        libs/transactions/transactions.c
        libs/reports/reports.h
        libs/reports/reports.c
        libs/importantUsers/importantUsers.c
        libs/importantUsers/importantUsers.h
        libs/activityLog/activityLog.h
        libs/activityLog/activityLog.c
        libs/misc/misc.c
        libs/misc/misc.h
        libs/misc/misc.c
        libs/misc/misc.h)
