#include "../../../global.h"
#include "../../../models/account.h"
#include "../../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void popAccount(AccountList *list) {
  if (list->head == NULL)
    return;

  AccountListItemPointer lastData = list->tail;
  AccountListItemPointer currentData = list->head;

  if (currentData == lastData) {
    free(lastData);
    list->head = NULL;
    list->tail = NULL;
  } else {
    while (currentData->next != lastData) {
      currentData = currentData->next;
    }
    currentData->next = NULL;
    list->tail = currentData;
    free(lastData);
  }
  list->length--;
}
