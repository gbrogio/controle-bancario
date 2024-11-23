#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <stdio.h>
#include <string.h>

char listAccountsScreen(AccountList *list, TransactionList *_,
                        AccountListItemPointer __) {
  UNUSED(_);
  UNUSED(__);

  cls();
  writeText("Entrou como: GERENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("b - Voltar para a tela anterior", SCREEN_WIDTH, SCREEN_HEIGHT - 3,
            0);

  writeText("LISTAGEM DE CONTAS", SCREEN_WIDTH / 2, 4, 0);
  writeText("1 - Listagem Geral", 0, 6, 0);
  writeText("2 - Listagem por Ordem Alfabetica", 0, 7, 0);
  writeText("3 - Listagem de Contas Inativas", 0, 8, 0);
  writeText("4 - Listagem de Contas-correntes", 0, 9, 0);
  writeText("5 - Consulta pelo Numero da Conta", 0, 10, 0);

  buildScreen();
  char option = command();

  if (option == '1') {
    listAccountsGeneral(list);
    option = '8';
    return option;
  }

  if (option == '2') {
    listAccountsAlphabetic(list);
    option = '8';
    return option;
  }

  if (option == '3') {
    listAccountsDisabled(list);
    option = '8';
    return option;
  }

  if (option == '4') {
    listAccountsChecking(list);
    option = '8';
    return option;
  }

  if (option == '5') {
    listAccountsByNumber(list);
    option = '8';
    return option;
  }

  return option;
}

char listAccounts(AccountList *list) {
  return controlSubScreen(listAccountsScreen, list, NULL, NULL);
}