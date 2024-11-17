
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../../models/account.h"
#include "../../../global.h"

void insertAccountIn(int position, AccountList *list, Account data)
{
  if (list->head == NULL || position < 0 || position > list->length)
    return;

  AccountListItemPointer newData = (AccountListItemPointer)malloc(sizeof(AccountListItem));
  newData->data = data;

  AccountListItemPointer currentData = list->head;
  AccountListItemPointer previousData = NULL;

  for (int i = 0; i < position; i++)
  {
    previousData = currentData;
    currentData = currentData->next;
  }

  if (previousData == NULL)
  {
    newData->next = list->head;
    list->head = newData;
  }
  else
  {
    previousData->next = newData;
    newData->next = currentData;
  }

  list->length++;
}
