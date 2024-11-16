#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"
#include "../../models/account.h"
#include "../../global.h"

void alterAccountInPostion(AccountList *list, Account account, int position)
{
  if (list->head == NULL || position < 0 || position > list->length)
    return;

  AccountListItemPointer currentData = list->head;

  for (int i = 0; i < position; i++)
  {
    currentData = currentData->next;
  }
}
