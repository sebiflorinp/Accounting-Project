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


# Accounting Project

## Features

1. Command line user interface which allows users to input and view financial data.
2. Users can create, edit, and delete financial accounts.
3. Financial transactions are recorded by the application and can be viewed by the users.
4. Users can view financial reports, such as account statements, balances, transaction registers, and expense reports.
5. Users must authenticate to access the accounting system and their data is encrypted in the database.
6. Users can input and manage information about customers or entities with whom they do business. 
7. An activity log is maintained and can be accessed by users with special previleges.

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

### Create a financial account

| Index |      Input      |                                      Output                                      |                           Description                           |
|:-----:|:---------------:|:--------------------------------------------------------------------------------:|:---------------------------------------------------------------:|
|  1.   |        1        |                                        -                                         |       The user has chosen to create a financial account.        |
|  2.   |        -        |                          Input the name of the account.                          |                   The user is asked to input                    |
|  3.   | Savings Account |                                        -                                         |            The input is received by the application.            |
|  4.   |        -        | Choose the type of the account:<br>  1. Savings<br>  2. Checking<br>  3. Credits |      The user is asked to choose the type of the account.       |
|  5.   |        1        |                                        -                                         |            The input is received by the application.            |
|  6.   |        -        |                      The account was created successfully.                       | The user is notified that the account was created successfully. |

<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

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
  
<div style="page-break-after: always"></div>

### Print the balance of all accounts

| Index | Input |                                     Output                                      |                         Description                          |
|:-----:|:-----:|:-------------------------------------------------------------------------------:|:------------------------------------------------------------:|
|  1.   |   9   |                                        -                                        | The user has chosen to display the balances of all accounts. |
|  2.   |   -   | Balances:<br> a list with the id, name and balance of all accounts of the user. |    The application displays the balance of all accounts.     |

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
  
<div style="page-break-after: always"></div>

### Update an important user from the list of important users

| Index |           Input           |                                         Output                                          |                                            Description                                            |
|:-----:|:-------------------------:|:---------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------:|
|  1.   |            13             |                                            -                                            |               The user has chosen to edit an user from the list of important users.               |
|  2.   |             -             | Input the id of the important user that will be edited:<br>A list with important users. | The user is asked to input the id of the important user that will be updated from the given list. |
|  3.   |             3             |                                            -                                            |                             The input is received by the application.                             |
|  4.   |             -             |                    Input the new description of the important user.                     |             The user is asked to input an updated description of the important user.              |
|  5.   | An really important user. |                                            -                                            |                             The input is received by the application.                             |
|  6.   |             -             |                           The user was updated successfully!                            |           The user is notified that the user with the input id was updated successfully           |
|
 
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