#include "menu.h"
#include "../../global/global.h"
#include "../../utils/screen/screen.h"
#include "../app/manager/login.h"

char loginScreen() {
  char option;
  cls();
  writeText("ENTRAR", SCREEN_WIDTH / 2, 4, 0);
  writeText("Deseja entrar como?", SCREEN_WIDTH / 2, 6, 0);
  writeText("1 - Gerente do banco", SCREEN_WIDTH / 2, 10, 0);
  writeText("2 - Cliente G.B.M.S.", SCREEN_WIDTH / 2, 12, 0);
  buildScreen();

  option = command();
  
  if (option == '1') {
    int success;
    do {
      success = loginManagerScreen();
    } while (success == 0);

    option = 'b';
    return option;
  } 
  
  return option;
}