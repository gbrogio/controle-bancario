#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"
#include "../../models/account.h"
#include "../../global.h"

AccountListItemPointer getAccountByNumber(AccountList *list, char number[])
{
  if (list->head == NULL)
  {
    Account emptyAccount;
    emptyAccount.code = -1;
    return NULL;
  }
}