
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "../models/account.h"
#include "../global.h"

AccountList *initializeAccountList()
{
  AccountList *list = (AccountList *)malloc(sizeof(AccountList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}
