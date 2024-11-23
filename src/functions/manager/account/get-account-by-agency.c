#include "../../../global.h"
#include "../../../models/account.h"
#include "../../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GetAccountBy getAccountByAgency(AccountList *list, char agency[],
                                int ignoreInactives) {
  GetAccountBy res = {NULL, -1};
  if (list->head == NULL)
    return res;

  AccountListItemPointer currentData = list->head;

  int position = 0;
  while (currentData != NULL) {
    if (ignoreInactives && strcmp(currentData->data.status, "inativo") == 0) {
      currentData = currentData->next;
      position++;
      continue;
    }

    if (strcmp(currentData->data.agency, agency) == 0) {
      res.account = currentData;
      res.position = position;
      return res;
    }
    currentData = currentData->next;
    position++;
  }

  return res;
}