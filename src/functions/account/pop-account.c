#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"
#include "../../models/account.h"
#include "../../global.h"

void popAccount(AccountList *list)
{
  if (list->head == NULL)
    return;

  AccountListItemPointer lastData = list->tail;
  AccountListItemPointer currentData = list->head;

  if (currentData == lastData)
  {
    free(lastData);
    list->head = NULL;
    list->tail = NULL;
  }
}
