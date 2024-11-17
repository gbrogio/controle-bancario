#include "../../models/transaction.h"
#include "../functions.h"
#include <stdlib.h>

void pushTransaction(TransactionList *list, Transaction data) {
  TransactionListItemPointer newData =
      (TransactionListItemPointer)malloc(sizeof(TransactionListItem));

  newData->data = data;
  newData->next = NULL;
  newData->prev = list->tail;

  if (list->head == NULL)
    list->head = newData;
  else
    list->tail->next = newData;

  list->tail = newData;
  list->length++;
}