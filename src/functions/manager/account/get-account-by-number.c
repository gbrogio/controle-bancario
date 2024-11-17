
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../../models/account.h"
#include "../../../global.h"

GetAccountByNumber getAccountByNumber(AccountList *list, char number[])
{
  GetAccountByNumber res = {NULL, -1};
  if (list->head == NULL)
    return res;

  AccountListItemPointer currentData = list->head;

  int position = 0;
  while (currentData != NULL)
  {
    if (strcmp(currentData->data.number, number) == 0) {
      res.account = currentData;
      res.position = position;
      return res;
    }
    currentData = currentData->next;
    position++;
  }

  return res;
}