#include "../functions/functions.h"
#include "../global.h"
#include "../models/account.h"
#include "../validations/validations.h"
#include "screens.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

AccountListItemPointer loginAccountScreen(AccountList *list) {
  cls();
  buildScreen();
  writeText("ENTRAR COMO CLIENTE", SCREEN_WIDTH / 2, 4, 0);
  writeText("Digite numero da conta.:", SCREEN_WIDTH / 2 - 26, 12, 1);
  writeText("Digite sua senha.......:", SCREEN_WIDTH / 2 - 26, 14, 1);

  char number[16];
  char password[10];

  getInput("%s", number, 16,
           "Digite um numero valido! Pressione 'Enter' para continuar...",
           SCREEN_WIDTH / 2, 12, validationNumberType, NULL);
  if (strcmp(number, "0") == 0) {
    AccountListItemPointer account =
        (AccountListItemPointer)malloc(sizeof(AccountListItem));
    account->data.code = -1;
    return account;
  }
  getInput("%s", password, 10,
           "Digite uma senha valida! Pressione 'Enter' para continuar...",
           SCREEN_WIDTH / 2, 14, validationPassword, NULL);

  clearFooter();
  char confirmation = confirm("Deseja entrar com essas credenciais?");
  if (confirmation != 's') {
    getchar();
    return NULL;
  }

  GetAccountBy accountFounded = getAccountByNumber(list, number, 1);

  if (accountFounded.account != NULL &&
      accountFounded.account->data.code != -1 &&
      strcmp(accountFounded.account->data.password, password) == 0) {
    return accountFounded.account;
  }

  clearFooter();
  printMessage("Numero ou senha invalidos!", 1);
  return NULL;
}
