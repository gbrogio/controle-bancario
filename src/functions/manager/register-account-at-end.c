#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void registerAccountAtEnd(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    clearFooter();
    if (account.code != 0)
    {
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        pushAccount(list, account);
    }
    clearFooter();
    doAgain = confirm("Deseja cadastrar outra conta?");
  } while (doAgain == 's');
}