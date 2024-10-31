#include <string.h>
#include <stdio.h>

#include "../../../global/global.h"
#include "../../../utils/screen/screen.h"
#include "./login.h"

int loginClientScreen(AccountList *list) {
  cls();
  buildScreen();
  writeText("ENTRAR COMO CLIENTE", SCREEN_WIDTH / 2, 4, 0);
  writeText("Digite numero da conta.:", SCREEN_WIDTH / 2 - 26, 12, 1);
  writeText("Digite sua senha.......:", SCREEN_WIDTH / 2 - 26, 14, 1);

  char number[9];
  char password[9];

  getInput("%s", number, "Digite um numero valido! Pressione 'Enter' para continuar...", SCREEN_WIDTH / 2, 12, validationNumberType, NULL);
  if (strcmp(number, "0") == 0) return 2;
  getInput("%s", password, "Digite uma senha valida! Pressione 'Enter' para continuar...", SCREEN_WIDTH / 2, 14, validationPassword, NULL);
  
  clearFooter();
  char confirmation = confirm("Deseja entrar com essas credenciais?");
  if (confirmation != 's') return 0;

  Account account = getAccountByNumber(list, number);

  if (account.code != -1 && strcmp(account.password, password) == 0) {
    return 1;
  }

  clearFooter();
  printMessage("Numero ou senha invalidos!");
  return 0;
}
