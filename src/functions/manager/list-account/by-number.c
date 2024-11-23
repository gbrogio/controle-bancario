#include "../../../global.h"
#include "../../../models/account.h"
#include "../../../validations/validations.h"
#include "../../functions.h"
#include <stddef.h>

void listAccountsByNumber(AccountList *list) {
  clearInputBuffer();
  char doAgain;
  do {
    cls();
    buildScreen();
    buildTableAccount(8);
    writeText("NUMERO:", 0, 5, 0);
    writeText("LISTAR CONTAS (NUMERO)", SCREEN_WIDTH / 2, 4, 0);

    char number[10];
    getInput("%s", number,
             "Digite um numero valido! Pressione 'Enter' para continuar...", 11,
             5, validationNumberType, list);
    GetAccountBy accountFounded = getAccountByNumber(list, number, 0);

    if (accountFounded.position != -1) {
      printAccountTable(accountFounded.account->data, 9);
    } else {
      changeForegroundColor(161, 161, 170);
      writeText("Nenhuma conta foi encontrada!", SCREEN_WIDTH / 2,
                SCREEN_HEIGHT / 2, 0);
      setDefaultColor();
    }

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    doAgain = confirm("Deseja listar outra conta?");
  } while (doAgain == 's');
}