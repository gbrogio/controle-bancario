
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../../models/account.h"
#include "../../../global.h"

void alterAccount(AccountListItemPointer account, Account data)
{
  if (account == NULL)
    return;

  strcpy(account->data.bank, data.bank);
  strcpy(account->data.agency, data.agency);
  strcpy(account->data.number, data.number);
  strcpy(account->data.status, data.status);
  strcpy(account->data.password, data.password);
  account->data.type = data.type;
  account->data.balance = data.balance;
  account->data.limit = data.limit;
  account->data.interestDay = data.interestDay;
}
