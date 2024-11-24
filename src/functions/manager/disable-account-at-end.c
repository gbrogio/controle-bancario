#include <stdlib.h>
#include <string.h>

#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"

void disableAccountAtEnd(AccountList *list) {
  if (list->length == 0) {
    printMessage("Nao ha contas cadastradas.", 1);
    return;
  }

  char doAgain = 's';
  do {
    cls();
    buildScreen();
    writeText("INATIVAR CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
    printAccount(list->tail->data, 0, 1);
    clearFooter();
    char confirmation = confirm("Deseja inativar essa conta?");
    if (confirmation == 's') {
      if (list->head->data.balance != 0) {
        printMessage("Conta com saldo diferente de zero! Pressione 'Enter' "
                     "para continuar...",
                     1);
        clearFooter();
        doAgain = confirm("Deseja inativar outra conta?");
        continue;
      }

      AccountListItemPointer lastAccount = list->tail;
      strcpy(lastAccount->data.status, "inativo");
    }
    clearFooter();
    doAgain = confirm("Deseja inativar outra conta?");
  } while (doAgain == 's');
}