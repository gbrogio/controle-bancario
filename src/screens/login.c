#include "login.h"
#include "../global.h"
#include "../models/account.h"
#include "../functions/functions.h"
#include "screens.h"

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
    return controlSubScreen(managerScreen(list));
  } 

  if (option == '2') {
    AccountListItemPointer account;
    do {
      account = loginClientScreen(list);
    } while (!account);
    if (account->data.code == -1) return 'b';
    return controlSubScreen(clientScreen(list, account));
  }
  
  return option;
}