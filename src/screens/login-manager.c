#include "../functions/functions.h"
#include "../global.h"
#include "../validations/validations.h"
#include "./screens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loginManagerScreen() {
  cls();
  buildScreen();
  writeText("ENTRAR COMO GERENTE", SCREEN_WIDTH / 2, 4, 0);
  writeText("Digite seu codigo.:", SCREEN_WIDTH / 2 - 21, 12, 1);
  writeText("Digite sua senha..:", SCREEN_WIDTH / 2 - 21, 14, 1);

  char code[50];
  char password[50];

  getInput("%s", code, 50,
           "Digite um codigo valido! Pressione 'Enter' para continuar...",
           SCREEN_WIDTH / 2, 12, noValid, NULL);
  if (strcmp(code, "0") == 0)
    return 2;
  getInput("%s", password, 50,
           "Digite uma senha valida! Pressione 'Enter' para continuar...",
           SCREEN_WIDTH / 2, 14, noValid, NULL);

  clearFooter();
  char confirmation = confirm("Deseja entrar com essas credenciais?");
  if (confirmation != 's') {
    getchar();
    return 0;
  }

  if (strcmp(code, ADM_CODE) == 0 && strcmp(password, ADM_PASSWORD) == 0) {
    return 1;
  }

  clearFooter();
  printMessage("Codigo ou senha invalidos!", 1);
  return 0;
}
