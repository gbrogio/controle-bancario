#include "../functions/functions.h"
#include "../global.h"
#include "screens.h"

void homeScreen() {
  cls();
  writeText("G.B.M.S. Bank - Trasferencias simples e rapidas", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1, 0);
  writeText("precione qualquer tecla para executar o app.", SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 1, 0);
  writeText("ou precione \"h\" para entrar na tela de ajuda.", SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 2, 0);
  buildScreen();
}