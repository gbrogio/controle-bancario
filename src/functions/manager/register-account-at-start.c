#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void registerAccountAtStart(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    clearFooter();
    if (account.code != 0)
    {
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        unshiftAccount(list, account);
    }
    clearFooter();
    doAgain = confirm("Deseja cadastrar outra conta?");
  } while (doAgain == 's');
}