#ifndef SCREEN_H
#define SCREEN_H
#include "../../utils/account/account.h"

void buildScreen();
char command();
char controlSubScreen(AccountList *list, char screen());

#endif 