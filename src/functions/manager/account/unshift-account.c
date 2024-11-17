
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../../models/account.h"
#include "../../../global.h"

void unshiftAccount(AccountList *list, Account data)
{
  AccountListItemPointer newData = (AccountListItemPointer)malloc(sizeof(AccountListItem));

  newData->data = data;
  newData->next = list->head;
  list->head = newData;
  if (list->tail == NULL)
    list->tail = newData;
  list->length++;
}
