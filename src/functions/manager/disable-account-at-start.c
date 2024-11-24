#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <stdlib.h>
#include <string.h>
/*
    Remove an account at the start of the list
    @param list The list of accounts
*/
void disableAccountAtStart(AccountList *list) {
  if (list->length == 0) {
    printMessage("Nao ha contas cadastradas.", 1);
    return;
  }

  cls();
  buildScreen();
  writeText("INATIVAR CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
  AccountListItemPointer firstAccount = list->head;
  AccountListItemPointer currentData = list->head;

  for (int i = 0; i < list->length; i++) {
    if (strcmp(currentData->data.status, "inativo") != 0) {
      firstAccount = currentData;
      break;
    }
    currentData = currentData->next;
  }

  printAccount(firstAccount->data, 0, 1);
  clearFooter();
  char confirmation = confirm("Deseja inativar essa conta?");
  if (confirmation == 's') {
    if (firstAccount->data.balance != 0) {
      printMessage("Conta com saldo diferente de zero! Pressione 'Enter' "
                   "para continuar...",
                   1);
      return;
    }

    strcpy(firstAccount->data.status, "inativo");
  }
  clearFooter();
}