#include "../../../global.h"
#include "../../../models/account.h"
#include "../../../validations/validations.h"
#include "../../functions.h"
#include <stddef.h>

void listAccountsByAgency(AccountList *list) {
  clearInputBuffer();
  char doAgain;
  do {
    cls();
    buildScreen();
    buildTableAccount(8);
    writeText("AGENCIA:", 0, 5, 0);
    writeText("LISTAR CONTAS (AGENCIA)", SCREEN_WIDTH / 2, 4, 0);

    char agency[8];
    getInput("%s", agency,
             "Digite uma agencia valida! Pressione 'Enter' para continuar...",
             11, 5, validationAgency, list);
    GetAccountBy accountFounded = getAccountByAgency(list, agency, 0);

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