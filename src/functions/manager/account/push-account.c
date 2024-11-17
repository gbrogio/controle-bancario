
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../../models/account.h"
#include "../../../global.h"

void pushAccount(AccountList *list, Account data)
{
  AccountListItemPointer newData = (AccountListItemPointer)malloc(sizeof(AccountListItem));

  newData->data = data;
  newData->next = NULL;

  if (list->head == NULL)
    list->head = newData;
  else
    list->tail->next = newData;

  list->tail = newData;
  list->length++;
}
