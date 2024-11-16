#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./functions.h"
#include "../models/transaction.h"

void pushTransaction(TransactionList *list, Transaction data)
{
  TransactionListItemPointer newData = (TransactionListItemPointer)malloc(sizeof(TransactionListItem));

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

/* 
void shiftTransaction(TransactionList *list)
{
  if (list->head == NULL)
    return;

  TransactionListItemPointer lastData = list->tail;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  free(lastData);
  list->length--;  
} */

TransactionList *initializeTransactionList()
{
  TransactionList *list = (TransactionList *)malloc(sizeof(TransactionList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}