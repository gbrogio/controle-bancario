#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void registerAccountAtPosition(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);

    writeText("Posicao..:", SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2, 0);
    int position;

    getInput("%d", &position,
             "Por favor digite uma posicao valida! Pressione 'Enter' para "
             "continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, invalidPosition, list);

    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    clearFooter();
    if (account.code != 0)
    {
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        insertAccountIn(position, list, account);
    }

    clearFooter();
    doAgain = confirm("Deseja cadastrar outra conta?");
  } while (doAgain == 's');
}