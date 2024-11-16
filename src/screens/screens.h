#ifndef SCREENS_H
#define SCREENS_H

#include "../models/account.h"

void helpScreen();
char loginScreen(AccountList *list);
void homeScreen();
int loginManagerScreen();
AccountListItemPointer loginAccountScreen(AccountList *list);
char managerScreen(AccountList *list);

#endif