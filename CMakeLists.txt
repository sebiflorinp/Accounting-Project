cmake_minimum_required(VERSION 3.27)
project(cp2 C)

set(CMAKE_C_STANDARD 11)

add_executable(cp2 main.c
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
        libs/importantUsers/importantUsers.h)
