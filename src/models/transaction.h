#ifndef TRANSACTION_MODEL_H
#define TRANSACTION_MODEL_H

/* Schema of accounts. Used on `TransactionListItem` structure */
typedef struct
{
  int id;
  char movimentDate[75];
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

#endif