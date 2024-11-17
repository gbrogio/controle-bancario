#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"

void registerAccountAtEnd(AccountList *list) {
  char doAgain;
  do {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    if (account.code != 0) {
      clearFooter();
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        pushAccount(list, account);
    }
    clearFooter();
    doAgain = confirm("Deseja cadastrar outra conta?");
  } while (doAgain == 's');
}