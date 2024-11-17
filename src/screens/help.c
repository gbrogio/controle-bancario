#include "../functions/functions.h"
#include "../global.h"
#include "screens.h"

void helpScreen() {
  cls();
  writeText("AJUDA", SCREEN_WIDTH / 2, 4, 0);
  writeText("Comandos permitidos:", 0, 6, 0);
  writeText("b - Voltar", 0, 10, 0);
  writeText("h - Abre a tela de ajuda", 0, 9, 0);
  writeText("x - Para o programa", 0, 8, 0);
  writeText("0 - Em campos de codigo, cancela e volta para a tela anterior", 0,
            11, 0);
  buildScreen();
  printMessage("Pressione qualquer tecla para continuar...");
}