<style>
    table {
        border-collapse: collapse;
        border-style: solid;
        border-color: black;
        border-width: thin;
    }

    td, th {
        border-style: solid;
        border-color: black;
        border-width: thin;
        padding: 4px;
    }
</style>


# C Project 2

## Statement

An accounting project involves managing financial and accounting data, performing financial
calculations, generating reports, and ensuring data security. Here are some common requirements
for such a project:
1. User Interface: Develop a user interface (UI) to allow users to input and view financial data. This
can be a command-line program or a graphical user interface (recommended). 10 points /20 points
2. Account Management: Allow users to create, edit, and delete financial accounts, such as savings
accounts, checking accounts, credit accounts, etc. 10 points
3. Transaction Recording: Implement functionality to record financial transactions, including
deposits, withdrawals, transfers, payments, and more. 10 points
4. Balance Calculation: Automatically calculate account balances based on recorded transactions.
10 points
5. Financial Reporting: Provide options for generating financial reports, such as account
statements, balances, transaction registers, and expense reports. 5 points
6. Security and Authentication: Ensure that financial data is protected, and users must authenticate
to access the accounting system. 5 points
7. Customer Data Management: Allow users to input and manage information about customers or
entities with whom they do business. 5 points
8. Data Export and Import: Offer options for exporting and importing financial data in and out of
various file formats (e.g., CSV, Excel, PDF export). 5 points
9. Input Data Validation: Perform checks on user-entered data to prevent errors or incorrect data.
10 points
10. Error and Exception Handling: Implement a system for proper error handling and handling
exceptional situations that may arise during the accounting process. 15 points
11. Audit and Logging: Maintain an activity log and provide audit capabilities to track changes and
activities related to accounts. 5 points
12. Documentation and Comments: Document the code (PDF) and add comments to make it easier
to understand. 10 points
13. Compliance with Specific Project Requirements: Ensure that the project meets the specific
requirements set by the instructor.
14. Presentation and Explanations: Ensure that you can explain and present the project to the
instructor or peers, highlighting key features and design decisions.

<div style="page-break-after: always"></div>

## Features

| Index |                          Feature                          |
|:-----:|:---------------------------------------------------------:|
|  1.1  |                  Create an user account.                  |
|  1.2  |                 Log into an user account.                 |
|  1.3  |               Sign out of an user account.                |
|  2.1  |                Create a financial account.                |
|  2.2  |                 Edit a financial account.                 |
|  2.3  |                Delete a financial account.                |
|  3.1  |                      Deposit money.                       |
|  3.2  |                      Withdraw money.                      |
|  3.3  |        Transfer money between financial accounts.         |
|  3.4  |                      Make a payment.                      |
|  4.1  |                   Record transactions.                    |
|  5.1  | Calculate the balance based on the recorded transactions. |
|  6.1  |        Print the statements of a selected account.        |
|  6.2  |            Print the balance of all accounts.             |
|  6.3  |       Print the transactions of a selected account.       |
|  6.4  |         Print the expenses of a selected account.         |
|  7.1  |        Add an user to the list of important users.        |
|  7.2  |        Edit the description of an important user.         |
|  7.3  |        Delete a user from the important user list.        |
|  7.4  |                 Display important users.                  |
|  8.1  |                   Have an activity log.                   |

<div style="page-break-after: always"></div>

## Runtime scenarios

### Create a user account

| Index |  Input   |                Output                 |                           Description                           |
|:-----:|:--------:|:-------------------------------------:|:---------------------------------------------------------------:|
|  1.   |    1     |                   -                   |          The user has chosen to create a user account.          |
|  2.   |    -     |          Input the username.          |           The user is asked to input their username.            |
|  3.   | Petrescu |                   -                   |               The user has input their username.                |
|  4.   |    -     |                   -                   |          The username is accepted by the application.           |
|  5.   |    -     |          Input the password.          |              The user is asked input the password.              |
|  6.   |   a1c2   |                   -                   |          The password is received by the application.           |
|  7.   |    -     |       Input the password again.       |         The user is asked to input the password again.          |
|  8.   |   a1c2   |                   -                   |            The input is received by the application.            |
|  9.   |    -     | The account was created successfully. | The user is notified that the account was created successfully. |

### Log into a user account

| Index |  Input   |              Output              |                     Description                      |
|:-----:|:--------:|:--------------------------------:|:----------------------------------------------------:|
|  1.   |    2     |                -                 |     The user has chosen to log into an account.      |
|  2.   |    -     |       Input the username.        |       The user is asked to input the username.       |
|  3.   | Petrescu |                -                 |     The username is received by the application.     |
|  4.   |    -     |       Input the password.        |       The user is asked to input to password.        |
|  5.   |   a1c2   |                -                 |      The input is received by the application.       |
|  6.   |    -     | You have logged in successfully. | The user is notified that the log in was successful. |

### Exit the application from the log in menu

| Index | Input |                Output                 |                        Description                         |
|:-----:|:-----:|:-------------------------------------:|:----------------------------------------------------------:|
|  1.   |   3   |                   -                   |        The user has chosen to exit the application.        |
|  2.   |   -   | Thank you for using this application! | The user receives a message and the application is closed. |

<div style="page-break-after: always"></div>

### Create a financial account

| Index |      Input      |                                      Output                                      |                           Description                           |
|:-----:|:---------------:|:--------------------------------------------------------------------------------:|:---------------------------------------------------------------:|
|  1.   |        1        |                                        -                                         |       The user has chosen to create a financial account.        |
|  2.   |        -        |                          Input the name of the account.                          |                   The user is asked to input                    |
|  3.   | Savings Account |                                        -                                         |            The input is received by the application.            |
|  4.   |        -        | Choose the type of the account:<br>  1. Savings<br>  2. Checking<br>  3. Credits |      The user is asked to choose the type of the account.       |
|  5.   |        1        |                                        -                                         |            The input is received by the application.            |
|  6.   |        -        |                      The account was created successfully.                       | The user is notified that the account was created successfully. |

### Edit a financial account

| Index |      Input       |                                              Output                                               |                               Description                                |
|:-----:|:----------------:|:-------------------------------------------------------------------------------------------------:|:------------------------------------------------------------------------:|
|  1.   |        2         |                                                 -                                                 |             The user has chosen to edit a financial account.             |
|  2.   |        -         | Input the ID of the financial account that will be edited:<br>The financial accounts of the user. |   The user is asked to choose a financial account by id from the list.   |
|  3.   |        3         |                                                 -                                                 |                The input is received by the application.                 |
|  4.   |        -         |                                Enter the new name of the account.                                 |         The user is asked to input the new name of the account.          |
|  5.   | Checking account |                                                 -                                                 |                The input is received by the application.                 |
|  6.   |        -         |        Choose the new type of the account:<br>  1. Savings<br>  2. Checking<br> 3. Credits        | The user is asked to choose the new account type from the received list. |
|  7.   |        2         |                                                 -                                                 |                The input is received by the application.                 |
|  8.   |        -         |                               The account was updated successfully.                               |     The user is notified that the account was updated successfully.      |

<div style="page-break-after: always"></div>

### Delete a financial account

| Index | Input |                                                    Output                                                     |                                 Description                                  |
|:-----:|:-----:|:-------------------------------------------------------------------------------------------------------------:|:----------------------------------------------------------------------------:|
|  1.   |   3   |                                                       -                                                       |              The user has chosen to delete a financial account.              |
|  2.   |   -   |       Input the ID of the financial account that will be edited:<br>The financial accounts of the user.       |     The user is asked to choose one of the accounts from the given list.     |
|  3.   |   1   |                                                       -                                                       |                  The input is received by the application.                   |
|  4.   |   -   | Do you want to delete the account financial account with the name Savings Account and the type Savings? (y/n) | The user is asked again if they want to delete the chosen financial account. |
|  5.   |   y   |                                                       -                                                       |                  The input is received by the application.                   |
|  6.   |   -   |                                     The account was deleted successfully.                                     |        The user is notified that the account was delete successfully.        |

### Deposit money into a financial account

| Index | Input |                                                Output                                                 |                                 Description                                 |
|:-----:|:-----:|:-----------------------------------------------------------------------------------------------------:|:---------------------------------------------------------------------------:|
|  1.   |   4   |                                                   -                                                   | The user has chosen to deposit an amount of money into a financial account. |
|  2.   |   -   | Input the id of the account in which the money will be deposited.<br> A list with financial accounts. |   The user is asked to choose one financial account from the given list.    |
|  3.   |   1   |                                                   -                                                   |                  The input is received by the application.                  |
|  4.   |   -   |                           Input the amount of money that will be deposited.                           |   The user is asked to input the amount of money that will be deposited.    |
|  5.   |  5.4  |                                                   -                                                   |                  The input is received by the application.                  |
|  6.   |   -   |                                  The deposit was made successfully!                                   |        The user is notified that the deposit was made successfully.         |

<div style="page-break-after: always"></div>

### Withdraw money from a financial account

| Index | Input |                                                 Output                                                  |                                 Description                                  |
|:-----:|:-----:|:-------------------------------------------------------------------------------------------------------:|:----------------------------------------------------------------------------:|
|  1.   |   5   |                                                    -                                                    | The user has chosen to withdraw an amount of money from a financial account. |
|  2.   |   -   | Input the id of the account from which the money will be withdrawn.<br> A list with financial accounts. |    The user is asked to choose one financial account from the given list.    |
|  3.   |   1   |                                                    -                                                    |                  The input is received by the application.                   |
|  4.   |   -   |                            Input the amount of money that will be withdrawn.                            |    The user is asked to input the amount of money that will be withdrawn.    |
|  5.   |   3   |                                                    -                                                    |                  The input is received by the application.                   |
|  6.   |   -   |                                  The withdrawal was made successfully!                                  |       The user is notified that the withdrawal was made successfully.        |

### Transfer money from a financial account to another

| Index | Input |                                                    Output                                                    |                                       Description                                       |
|:-----:|:-----:|:------------------------------------------------------------------------------------------------------------:|:---------------------------------------------------------------------------------------:|
|  1.   |   6   |                                                      -                                                       | The user has chosen to transfer an amount of money from a financial account to another. |
|  2.   |   -   |  Input the id of the account from which the money will be transferred.<br> A list with financial accounts.   |         The user is asked to choose one financial account from the given list.          |
|  3.   |   1   |                                                      -                                                       |                        The input is received by the application.                        |
|  4.   |   -   |                      Input the id of the account to which to money will be transferred.                      |  The user is asked to input the id of the account in which the transfer will be made.   |
|  5.   |  12   |                                                      -                                                       |                        The input is received by the application.                        |
|  6.   |   -   |                             Input the amount of money that will be transferred.                              |        The user is asked to input the amount of money that will be transferred.         |
|  7.   |   3   |                                                      -                                                       |                        The input is received by the application.                        |
|  8.   |   -   | Do you want to transfer $3 from <account name> to <account name> which is owned by <account username>? (y/n) |                       The user is asked to confirm the transfer.                        |
|  9.   |   y   |                                                      -                                                       |                           The application receives the input.                           |
|  10.  |   -   |                                         The transfer was successful!                                         |                 The user is notified that the transfer was successful.                  |

<div style="page-break-after: always"></div>

### Make a payment from a financial account

| Index | Input |                                                  Output                                                   |                                       Description                                        |
|:-----:|:-----:|:---------------------------------------------------------------------------------------------------------:|:----------------------------------------------------------------------------------------:|
|  1.   |   7   |                                                     -                                                     | The user has chosen to make a payment using an amount of money from a financial account. |
|  2.   |   -   | Input the id of the account from which money will be used as payment.<br> A list with financial accounts. |          The user is asked to choose one financial account from the given list.          |
|  3.   |   1   |                                                     -                                                     |                        The input is received by the application.                         |
|  4.   |   -   |                          Input the amount of money that will be used as payment.                          |       The user is asked to input the amount of money that will be used as payment.       |
|  5.   |   3   |                                                     -                                                     |                        The input is received by the application.                         |
|  6.   |   -   |                                    The payment was made successfully!                                     |               The user is notified that the payment was made successfully.               |

### Print the statements of a selected account

| Index | Input |                              Output                               |                                      Description                                      |
|:-----:|:-----:|:-----------------------------------------------------------------:|:-------------------------------------------------------------------------------------:|
|  1.   |   8   |                                 -                                 |         The user has chosen to display the statements of a selected account.          |
|  2.   |   -   |        Input the id of the account:<br>A list of accounts.        | The user is asked to input the id of the account of which the statement will be made. |
|  3.   |   2   |                                 -                                 |                       The input is received by the application.                       |
|  4.   |   -   | Statement <br>A list with all transactions from the last 31 days. |          The application displays all transactions made in the last 31 days.          |

### Print the balance of all accounts

| Index | Input |                                     Output                                      |                         Description                          |
|:-----:|:-----:|:-------------------------------------------------------------------------------:|:------------------------------------------------------------:|
|  1.   |   9   |                                        -                                        | The user has chosen to display the balances of all accounts. |
|  2.   |   -   | Balances:<br> a list with the id, name and balance of all accounts of the user. |    The application displays the balance of all accounts.     |

<div style="page-break-after: always"></div>

### Print the transactions of a selected account

| Index | Input |                       Output                        |                                          Description                                          |
|:-----:|:-----:|:---------------------------------------------------:|:---------------------------------------------------------------------------------------------:|
|  1.   |  10   |                          -                          |             The user has chosen to display the transaction of a selected account.             |
|  2.   |   -   | Input the id of the account:<br>A list of accounts. | The user is asked to input the id of the account of which the transactions will be displayed. |
|  3.   |   1   |                          -                          |                           The input is received by the application.                           |
|  4.   |   -   |      Transactions:<br>A list of transactions.       | The application displays the transactions that were made using the account with the input id. |

### Print the expenses of a selected account

| Index | Input |                       Output                        |                                        Description                                        |
|:-----:|:-----:|:---------------------------------------------------:|:-----------------------------------------------------------------------------------------:|
|  1.   |  11   |                          -                          |            The user has chosen to display the expenses of a selected account.             |
|  2.   |   -   | Input the id of the account:<br>A list of accounts. | The user is asked to input the id of the account of which the expenses will be displayed. |
|  3.   |   1   |                          -                          |                         The input is received by the application.                         |
|  4.   |   -   |          Expenses:<br>A list of expenses.           | The application displays the expenses that were made using the account with the input id. |

<div style="page-break-after: always"></div>

### Add a user to the list of important users

| Index |       Input        |                             Output                              |                                                 Description                                                 |
|:-----:|:------------------:|:---------------------------------------------------------------:|:-----------------------------------------------------------------------------------------------------------:|
|  1.   |         12         |                                -                                |                     The user has chosen to add an user in the list of important users.                      |
|  2.   |         -          |               Input the id of the important user.               |                          The user is asked to input the id of the important user.                           |
|  3.   |         3          |                                -                                |                                  The input is received by the application.                                  |
|  4.   |         -          |           Input a description for the important user.           |                       The user is asked to input a description of the important user.                       |
|  5.   | An important user. |                                -                                |                                  The input is received by the application.                                  |
|  6.   |         -          | The user was added successfully in the list of important users! | The user is notified that the user with the input id was added successfully in the list of important users. |

### Update an important user from the list of important users

| Index |           Input           |                                         Output                                          |                                            Description                                            |
|:-----:|:-------------------------:|:---------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------:|
|  1.   |            13             |                                            -                                            |               The user has chosen to edit an user from the list of important users.               |
|  2.   |             -             | Input the id of the important user that will be edited:<br>A list with important users. | The user is asked to input the id of the important user that will be updated from the given list. |
|  3.   |             3             |                                            -                                            |                             The input is received by the application.                             |
|  4.   |             -             |                    Input the new description of the important user.                     |             The user is asked to input an updated description of the important user.              |
|  5.   | An really important user. |                                            -                                            |                             The input is received by the application.                             |
|  6.   |             -             |                           The user was updated successfully!                            |          The user is notified that the user with the input id was updated successfully.           |

<div style="page-break-after: always"></div>

### Delete an important user from the list of important users

| Index | Input |                                            Output                                             |                                            Description                                            |
|:-----:|:-----:|:---------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------:|
|  1.   |  14   |                                               -                                               |              The user has chosen to delete an user from the list of important users.              |
|  2.   |   -   |   Input the id of the important user that will be deleted:<br>A list with important users.    | The user is asked to input the id of the important user that will be deleted from the given list. |
|  3.   |   3   |                                               -                                               |                             The input is received by the application.                             |
|  4.   |   -   | Do you want to delete the user <username> with the following description <description>? (y/n) |                            The user is asked to confirm the operation.                            |
|  5.   |   y   |                                               -                                               |                             The input is received by the application.                             |
|  6.   |   -   |              The user was deleted successfully from the list of important users.              |   The user is notified that the user was deleted successfully from the list of important users.   |

### Display important users

| Index | Input |              Output              |                              Description                               |
|:-----:|:-----:|:--------------------------------:|:----------------------------------------------------------------------:|
|  1.   |  15   |                -                 | The user has chosen to display a list with all of the important users. |
|  2.   |   -   | A list with all important users. |    The application displays a list with all of the important users.    |

### Sign out

| Index | Input |                 Output                 |                         Description                          |
|:-----:|:-----:|:--------------------------------------:|:------------------------------------------------------------:|
|  1.   |  16   |                   -                    |               The user has chosen to sign out.               |
|  2.   |   -   | You have been signed out successfully! | The user is notified that they were signed out successfully. |





