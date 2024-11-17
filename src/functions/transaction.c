#include <stdlib.h>
#include "./functions.h"
#include "../models/transaction.h"

TransactionList *initializeTransactionList()
{
  TransactionList *list = (TransactionList *)malloc(sizeof(TransactionList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}