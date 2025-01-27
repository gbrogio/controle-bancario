#include "../../../global.h"
#include "../../../models/account.h"
#include "../../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertAccountIn(int position, AccountList *list, Account data) {
  if (position < 0 || position > list->length)
    return;

  if (list->head == NULL) {
    pushAccount(list, data);
    return;
  }

  AccountListItemPointer newData =
      (AccountListItemPointer)malloc(sizeof(AccountListItem));
  newData->data = data;

  AccountListItemPointer currentData = list->head;
  AccountListItemPointer previousData = NULL;

  for (int i = 0; i < position; i++) {
    previousData = currentData;
    currentData = currentData->next;
  }

  if (previousData == NULL) {
    newData->next = list->head;
    list->head = newData;
  } else {
    previousData->next = newData;
    newData->next = currentData;
  }

  list->length++;
}
