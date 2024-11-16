#ifndef SCREENS_H
#define SCREENS_H

#include "../models/account.h"
#include "../models/transaction.h"

void helpScreen();
char loginScreen(AccountList *list, TransactionList *transactionList);
void homeScreen();
int loginManagerScreen();
AccountListItemPointer loginAccountScreen(AccountList *list);
char managerScreen(AccountList *list);
char accountScreen(AccountList *accountList, TransactionList *transactionList, AccountListItemPointer client);

#endif