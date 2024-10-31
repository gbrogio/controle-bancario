#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../global/global.h"
#include "../../../utils/screen/screen.h"
#include "./screen.h"
#include "../../../utils/account/account.h"

char clientScreen(AccountList *list)
{
  char option;
  cls();
  writeText("BEM VINDO DE VOLTA!", SCREEN_WIDTH, 4, 0);
  writeText("Entrou como: CLIENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("b - Voltar para a tela de login", SCREEN_WIDTH, SCREEN_HEIGHT - 3, 0);

  buildScreen();

  option = command();

  return option;
}
