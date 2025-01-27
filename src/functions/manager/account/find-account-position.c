#include "../../../global.h"
#include "../../../models/account.h"
#include "../../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findAccountPosition(AccountList *list, char number[]) {
  if (list->head == NULL)
    return -1;

  AccountListItemPointer currentData = list->head;
  int position = 0;

  while (currentData != NULL) {
    if (strcmp(currentData->data.number, number) == 0)
      return position;
    currentData = currentData->next;
    position++;
  }

  return -1;
}