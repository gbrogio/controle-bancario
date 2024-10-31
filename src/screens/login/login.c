#include "menu.h"
#include "../../global/global.h"
#include "../../utils/screen/screen.h"
#include "../app/manager/login.h"
#include "../app/manager/screen.h"
#include "../app/client/login.h"
#include "../app/client/screen.h"
#include "../../utils/account/account.h"

char loginScreen(AccountList *list) {
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
    return controlSubScreen(list, managerScreen);
  } 

  if (option == '2') {
    int status;
    do {
      status = loginClientScreen(list);
    } while (status == 0);
    if (status != 1) return 'b';
    return controlSubScreen(list, clientScreen);
  }
  
  return option;
}