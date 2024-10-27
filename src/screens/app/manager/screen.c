#include <string.h>
#include <stdio.h>

#include "../../../global/global.h"
#include "../../../utils/screen/screen.h"
#include "./screen.h"

char managerScreen() {
  char option;
  cls();
  buildScreen();
  writeText("BEM VINDO DE VOLTA!", SCREEN_WIDTH, 4, 0);
  writeText("Entrou como: GERENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("1 - ", 0, 6, 0);
  writeText("b - Voltar para a tela de login", SCREEN_WIDTH, SCREEN_HEIGHT - 3, 0);
  

  option = command();
  
  return option;
}
