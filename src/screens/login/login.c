#include "menu.h"
#include "../../global/global.h"
#include "../../utils/screen/screen.h"
#include "../app/manager/login.h"
#include "../app/manager/screen.h"

char loginScreen() {
  char option;
  cls();
  writeText("ENTRAR", SCREEN_WIDTH / 2, 4, 0);
  writeText("Selecione um tipo de conta:", SCREEN_WIDTH / 2, 6, 0);
  writeText("1 - Gerente do banco", SCREEN_WIDTH / 2 - 2, 10, 0);
  writeText("2 - Cliente G.B.M.S.", SCREEN_WIDTH / 2 - 2, 12, 0);
  buildScreen();

  option = command();
  
  if (option == '1') {
    int status;
    do {
      status = loginManagerScreen();
    } while (status == 0);
    if (status != 1) return 'b';
    return controlSubScreen(managerScreen);
  } 
  
  return option;
}