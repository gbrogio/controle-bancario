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
 * @param account Pointer to the account list item.
 * @param data Account data to be altered.
 */
void alterAccount(AccountListItemPointer account, Account data);

typedef struct {
  AccountListItemPointer account;
  int position;
} GetAccountByNumber;

/**
 * @brief Retrieves an account from the account list by its number.
 * 
 * @param list Pointer to the account list.
 * @param number Account number to search for.
 * @param ignoreInactives Flag to indicate if inactive accounts should be ignored.
 * 
 * @return AccountListItemPointer Pointer to the account list item, or NULL if not found.
 */
GetAccountByNumber getAccountByNumber(AccountList *list, char number[], int ignoreInactives);

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
 * @brief Prints an account.
 * 
 * @param account Account to be printed.
 * @param hiddenMoney Flag to indicate if money fields (e.g. balance, limit) should be hidden.
 * @param hiddenSensitiveData Flag to indicate if sensitive data should be hidden.
 */
void printAccount(Account account, int hiddenMoney, int hiddenSensitiveData);

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
void alterAccountScreen(AccountList *list);

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
 * @param from Pointer to the account to transfer from.
 * @param to Pointer to the account to transfer to.
 * @param type Type of transaction.
 * 
 * @return Transaction New transaction.
 */
Transaction createTransaction(TransactionList *list, AccountListItem *from, AccountListItem *to, char type);

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

/**
 * @brief Registers a transaction.
 * 
 * @param list Pointer to the transaction list.
 * @param account Pointer to the account.
 * @param type Type of transaction.
 */
void registerTransaction(TransactionList *list, AccountListItem *account, char type);

/**
 * @brief Adds a new transaction to the end of the transaction list.
 * 
 * @param list Pointer to the transaction list.
 * @param data Transaction data to be added.
 */
void pushTransaction(TransactionList *list, Transaction data);

/**
 * @brief Transfers money between accounts.
 * 
 * @param accountList Pointer to the account list.
 * @param transactionList Pointer to the transaction list.
 * @param account Pointer to the account.
 */
void transfer(AccountList *accountList, TransactionList *transactionList, AccountListItem *account);

/**
 * @brief Gives the yield of an account.
 * 
 * @param account Pointer to the account.
 * @return double Yield of the account.
 */
double giveYieldTo(AccountListItemPointer account, TransactionList *transactionList);

void buildScreen();
char command();
char controlSubScreen(char screen(
                          AccountList *list, TransactionList *transactionList, AccountListItemPointer account),
                      AccountList *list, TransactionList *transactionList, AccountListItemPointer account);

#endif