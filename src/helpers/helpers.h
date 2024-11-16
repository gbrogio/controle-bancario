#ifndef HELPERS_H
#define HELPERS_H

#include "../models/account.h"

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
 * @brief initializes a new account list.
 * 
 * @return AccountList* Pointer to the new account list.
 */
AccountList *initializeAccountList();

#endif