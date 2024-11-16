#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "../global.h"
#include "../functions/functions.h"
#include "../validations/validations.h"
#include "../models/account.h"
#include "screens.h"

AccountListItemPointer loginAccountScreen(AccountList *list) {
  cls();
  buildScreen();
  writeText("ENTRAR COMO CLIENTE", SCREEN_WIDTH / 2, 4, 0);
  writeText("Digite numero da conta.:", SCREEN_WIDTH / 2 - 26, 12, 1);
  writeText("Digite sua senha.......:", SCREEN_WIDTH / 2 - 26, 14, 1);

  char number[9];
  char password[9];

  getInput("%s", number, "Digite um numero valido! Pressione 'Enter' para continuar...", SCREEN_WIDTH / 2, 12, validationNumberType, NULL);
  if (strcmp(number, "0") == 0) {
    AccountListItemPointer account = (AccountListItemPointer) malloc(sizeof(AccountListItem));
    account->data.code = -1;
    return account;
  }
  getInput("%s", password, "Digite uma senha valida! Pressione 'Enter' para continuar...", SCREEN_WIDTH / 2, 14, validationPassword, NULL);
  
  clearFooter();
  char confirmation = confirm("Deseja entrar com essas credenciais?");
  if (confirmation != 's') return NULL;

  AccountListItemPointer account = getAccountByNumber(list, number);

  if (account->data.code != -1 && strcmp(account->data.password, password) == 0) {
    return account;
  }

  clearFooter();
  printMessage("Numero ou senha invalidos!");
  return NULL;
}
