#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"
#include "../../models/account.h"
#include "../../global.h"

void shiftAccount(AccountList *list)
{
  if (list->head == NULL)
    return;

  AccountListItemPointer firstData = list->head;
  list->head = list->head->next;
  free(firstData);
  list->length--;

  if (list->head == NULL)
    list->tail = NULL;
}
