cmake_minimum_required(VERSION 3.27)
project(cp2 C)

set(CMAKE_C_STANDARD 11)

add_executable(cp2 main.c
        libs/validation/validation.h
        libs/validation/validation.c
        libs/dbInteraction/users/users.h
        libs/models/models.h
        libs/dbInteraction/users/users.c
        libs/dbInteraction/accounts/accounts.h
        libs/dbInteraction/accounts/accounts.c)
