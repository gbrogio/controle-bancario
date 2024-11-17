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
    printMessage("Nao ha contas cadastradas.");
    awaitPressAnyKey(0);
    return;
  }

  char doAgain = 's';
  do {
    cls();
    buildScreen();
    writeText("INATIVAR CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
    printAccount(list->head->data, 0, 1);
    clearFooter();
    char confirmation = confirm("Deseja inativar essa conta?");
    if (confirmation == 's') {
      if (list->head->data.balance != 0) {
        printMessage("Conta com saldo diferente de zero! Pressione 'Enter' "
                     "para continuar...");
        clearFooter();
        doAgain = confirm("Deseja inativar outra conta?");
        continue;
      }

      AccountListItemPointer firstAccount = list->head;
      strcpy(firstAccount->data.status, "inativo");
    }
    clearFooter();
    doAgain = confirm("Deseja inativar outra conta?");
  } while (doAgain == 's');
}