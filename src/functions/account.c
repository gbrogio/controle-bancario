#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global.h"
#include "../models/account.h"
#include "functions.h"

AccountList *initializeAccountList() {
  AccountList *list = (AccountList *)malloc(sizeof(AccountList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}
