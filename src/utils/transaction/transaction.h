#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../account/account.h"
#include "../../global/global.h"

/* Schema of accounts. Used on `TransactionListItem` structure */
typedef struct
{
  int id;
  char movimentDate[23];
  char type;
  double value;

  double balance;
  char accountNumber[9];
} Transaction;

typedef struct TransactionListItem *TransactionListItemPointer;

/*
  @param data Is the `Transaction` data.
  @param next Is a pointer for the next `Transaction` in list
*/
typedef struct TransactionListItem
{
  Transaction data;
  TransactionListItemPointer next;
  TransactionListItemPointer prev;
} TransactionListItem;

/*
  @param head A pointer for the first item in list
  @param tail A pointer for the last item in list
  @param length The length of the list
*/
typedef struct
{
  TransactionListItemPointer head;
  TransactionListItemPointer tail;
  int length;
} TransactionList;

void pushTransaction(TransactionList *list, Transaction data);
TransactionList *initializeTransactionList();
Transaction createTransaction(TransactionList *list, AccountListItem *account, char type);
void printTransaction(Transaction account);
Transaction printTransactionInPosition(TransactionList *list, int position);

#endif