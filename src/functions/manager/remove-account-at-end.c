#include <stddef.h>
#include <stdlib.h>

#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void removeAccountAtEnd(AccountList *list)
{
  if (list->length == 0)
  {
    printMessage("Nao ha contas cadastradas.");
    awaitPressAnyKey(0);
    return;
  }

  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, list->length - 1);
    clearFooter();
    char confirmation = confirm("Deseja remover essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      AccountListItemPointer lastAccount = list->tail;
      AccountListItemPointer previousAccount = list->head;

      for (int i = 0; i < list->length - 1; i++)
      {
        previousAccount = previousAccount->next;
      }
      list->tail = previousAccount;
      previousAccount->next = NULL;
      free(lastAccount);

      list->length--;
    }
    clearFooter();
    doAgain = confirm("Deseja remover outra conta?");
  } while (doAgain == 's');
}