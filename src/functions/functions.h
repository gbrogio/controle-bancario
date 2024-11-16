#ifndef HELPERS_H
#define HELPERS_H

#include "../models/account.h"
#include "../models/transaction.h"

/**
 * @brief Adds a new account to the end of the account list.
 * 
 * @param list Pointer to the account list.
 * @param data Account data to be added.
 */
void pushAccount(AccountList *list, Account data);

/**
 * @brief Inserts a new account at a specific position in the account list.
 * 
 * @param position Position to insert the new account.
 * @param list Pointer to the account list.
 * @param data Account data to be inserted.
 */
void insertAccountIn(int position, AccountList *list, Account data);

/**
 * @brief Adds a new account to the beginning of the account list.
 * 
 * @param list Pointer to the account list.
 * @param data Account data to be added.
 */
void unshiftAccount(AccountList *list, Account data);

/**
 * @brief Removes the first account from the account list.
 * 
 * @param list Pointer to the account list.
 */
void shiftAccount(AccountList *list);

/**
 * @brief Removes the last account from the account list.
 * 
 * @param list Pointer to the account list.
 */
void popAccount(AccountList *list);

/**
 * @brief Alters the account data at a specific position in the account list.
 * 
 * @param list Pointer to the account list.
 * @param account New account data.
 * @param position Position of the account to be altered.
 */
void alterAccountInPostion(AccountList *list, Account account, int position);

/**
 * @brief Finds the position of an account in the account list by its number.
 * 
 * @param list Pointer to the account list.
 * @param number Account number to search for.
 * @return int Position of the account in the list, or -1 if not found.
 */
int findAccountPosition(AccountList *list, char number[]);

/**
 * @brief Retrieves an account from the account list by its number.
 * 
 * @param list Pointer to the account list.
 * @param number Account number to search for.
 * @return AccountListItemPointer Pointer to the account list item, or NULL if not found.
 */
AccountListItemPointer getAccountByNumber(AccountList *list, char number[]);

/**
 * @brief Initializes a new account list.
 * 
 * @return AccountList* Pointer to the new account list.
 */
AccountList *initializeAccountList();

/**
 * @brief Adds a new transaction to the end of the transaction list.
 * 
 * @param list Pointer to the transaction list.
 * @param data Transaction data to be added.
 */
void pushTransaction(TransactionList *list, Transaction data);

/**
 * @brief Initializes a new transaction list.
 * 
 * @return TransactionList* Pointer to the new transaction list.
 */
TransactionList *initializeTransactionList();

/**
 * @brief Prints a transaction.
 * 
 * @param transaction Transaction to be printed.
 */
Account printAccountInPosition(AccountList *list, int position);

/**
 * @brief Prints an account.
 * 
 * @param account Account to be printed.
 */
void printAccount(Account account);

/**
 * @brief Creates a new account.
 * 
 * @param list Pointer to the account list.
 * @param update Flag to indicate if the account is being updated.
 * @param input Flag to indicate if the account is being input.
 * @return Account New account.
 */
Account createAccount(AccountList *list, int update, int input);

/**
 * @brief Removes the account at the end of the list.
 * 
 * @param list Pointer to the AccountList structure.
 */
void disableAccountAtEnd(AccountList *list);

/**
 * @brief Alters the details of an existing account in the list.
 * 
 * @param list Pointer to the AccountList structure.
 */
void alterAccount(AccountList *list);

/**
 * @brief Registers a new account at the start of the list.
 * 
 * @param list Pointer to the AccountList structure.
 */
void registerAccountAtStart(AccountList *list);

/**
 * @brief Registers a new account at a specific position in the list.
 * 
 * @param list Pointer to the AccountList structure.
 */
void registerAccountAtPosition(AccountList *list);

/**
 * @brief Lists all the accounts in the list.
 * 
 * @param list Pointer to the AccountList structure.
 */
void listAccounts(AccountList *list);

/**
 * @brief Registers a new account at the end of the list.
 * 
 * @param list Pointer to the AccountList structure.
 */
void registerAccountAtEnd(AccountList *list);

/**
 * @brief Removes an account from the list by its account number.
 * 
 * @param list Pointer to the AccountList structure.
 */
void disableAccountByNumber(AccountList *list);

/**
 * @brief Removes an account from the list by its position.
 * 
 * @param list Pointer to the AccountList structure.
 */
void disableAccountAtStart(AccountList *list);

/**
 * @brief Removes an account from the list by its position.
 * 
 * @param list Pointer to the AccountList structure.
 */
void disableAccountAtEnd(AccountList *list);

/**
 * @brief Creates a new transaction.
 * 
 * @param list Pointer to the transaction list.
 * @param account Pointer to the account.
 * @param type Type of transaction.
 * 
 * @return Transaction New transaction.
 */
Transaction createTransaction(TransactionList *list, AccountListItem *account, char type);

/**
 * @brief Saves the account list to a file.
 * 
 * @param list Pointer to the account list.
 * @param filename Name of the file to save the account list to.
 */
void saveAccounts(AccountList *list, char *filename);

/**
 * @brief Loads the account list from a file.
 * 
 * @param list Pointer to the account list.
 * @param filename Name of the file to load the account list from.
 */
void loadAccounts(AccountList *list, char *filename);

/**
 * @brief Saves the transaction list to a file.
 * 
 * @param list Pointer to the transaction list.
 * @param filename Name of the file to save the transaction list to.
 */
void saveTransactions(TransactionList *list, char *filename);

/**
 * @brief Loads the transaction list from a file.
 * 
 * @param list Pointer to the transaction list.
 * @param filename Name of the file to load the transaction list from.
 */
void loadTransactions(TransactionList *list, char *filename);

void buildScreen();
char command();
char controlSubScreen(char screen(
                          AccountList *list, TransactionList *transactionList, AccountListItemPointer account),
                      AccountList *list, TransactionList *transactionList, AccountListItemPointer account);

#endif