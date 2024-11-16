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
void removeAccountAtStart(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, 0);
    clearFooter();
    char confirmation = confirm("Deseja remover essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      AccountListItemPointer firstAccount = list->head;
      list->head = list->head->next;
      free(firstAccount);
      list->length--;
    }
    clearFooter();
    doAgain = confirm("Deseja remover outra conta?");
  } while (doAgain == 's');
}