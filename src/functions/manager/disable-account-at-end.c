#include <stdlib.h>
#include <string.h>

#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"

void disableAccountAtEnd(AccountList *list)
{
  if (list->length == 0)
  {
    printMessage("Nao ha contas cadastradas.", 1);
    return;
  }

  cls();
  buildScreen();
  writeText("INATIVAR CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
  AccountListItemPointer lastAccount = NULL;
  AccountListItemPointer currentData = list->head;
  for (int i = 0; i < list->length; i++)
  {
    if (strcmp(currentData->data.status, "inativo") != 0)
    {
      lastAccount = currentData;
    }
    currentData = currentData->next;
  }

  if (lastAccount == NULL)
  {
    printMessage("Nao ha contas ativas.", 1);
    return;
  }

  clearFooter();
  char confirmation = confirm("Deseja inativar essa conta?");
  if (confirmation == 's')
  {
    if (lastAccount->data.balance != 0)
    {
      printMessage("Conta com saldo diferente de zero! Pressione 'Enter' "
                   "para continuar...",
                   1);
      return;
    }

    strcpy(lastAccount->data.status, "inativo");
  }
}