#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../functions.h"
#include "../../models/account.h"
#include "../../global.h"

Account printAccountInPosition(AccountList *list, int position)
{
  AccountListItemPointer account = list->head;
  for (int i = 0; i < position; i++)
    account = account->next;

  printAccount(account->data);

  return account->data;
}