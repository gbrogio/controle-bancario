#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void disableAccountByNumber(AccountList *list) {
  if (list->length == 0) {
    printMessage("Nao ha contas cadastradas.", 1);
    return;
  }

  char doAgain = 's';
  do {
    cls();
    buildScreen();
    writeText("INATIVAR CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 14, SCREEN_HEIGHT / 2,
              0);

    char number[16];
    getchar();
    getInput("%s", number, 16,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, list);

    if (number[0] == '0') {
      clearFooter();
      doAgain = confirm("Deseja inativar outra conta?");
      continue;
    }

    GetAccountBy accountFounded = getAccountByNumber(list, number, 0);

    if (accountFounded.position == -1) {
      printMessage("Conta nao encontrada! Pressione 'Enter' para continuar...",
                   0);
      doAgain = confirm("Deseja alterar outra conta?");

      continue;
    }

    if (accountFounded.account->data.balance != 0) {
      printMessage("Conta com saldo diferente de zero! Pressione 'Enter' para "
                   "continuar...",
                   0);
      clearFooter();
      doAgain = confirm("Deseja inativar outra conta?");
      continue;
    }

    cls();
    buildScreen();
    writeText("INATIVAR CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);
    printAccount(accountFounded.account->data, 0, 1);
    clearFooter();
    char confirmation = confirm("Deseja inativar essa conta?");
    if (confirmation == 's') {
      if (list->head == NULL)
        return;
      if (accountFounded.position == 0) {
        AccountListItemPointer firstAccount = list->head;
        strcpy(firstAccount->data.status, "inativo");
      } else {
        AccountListItemPointer previousAccount = list->head;
        for (int i = 0; i < accountFounded.position - 1; i++) {
          previousAccount = previousAccount->next;
        }
        AccountListItemPointer currentAccount = previousAccount->next;
        previousAccount->next = currentAccount->next;
        free(currentAccount);
      }

      list->length--;
    }

    clearFooter();
    doAgain = confirm("Deseja inativar outra conta?");
  } while (doAgain == 's');
}