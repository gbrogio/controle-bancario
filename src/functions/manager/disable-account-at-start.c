#include <stddef.h>
#include <stdlib.h>

#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
/*
    Remove an account at the start of the list
    @param list The list of accounts
*/
void disableAccountAtStart(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("INATIVAR CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, 0);
    clearFooter();
    char confirmation = confirm("Deseja inativar essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      AccountListItemPointer firstAccount = list->head;
      strcpy(firstAccount->data.status, "inativo");
    }
    clearFooter();
    doAgain = confirm("Deseja inativar outra conta?");
  } while (doAgain == 's');
}