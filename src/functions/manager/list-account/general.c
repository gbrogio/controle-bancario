#include "../../../global.h"
#include "../../../models/account.h"
#include "../../functions.h"
#include <stddef.h>

void listAccountsGeneral(AccountList *list) {
  AccountListItemPointer account = list->head;
  int page = 1;
  int noAccounts = 0;
  char continueListing;
  clearInputBuffer();

  do {
    cls();
    buildScreen();
    writeText("LISTAR CONTAS (GERAL)", SCREEN_WIDTH / 2, 4, 0);
    buildTableAccount(7);

    int printed = 0;
    for (int i = page * 0; i < 16; i++) {
      if (account == NULL) {
        noAccounts = 1;
        break;
      }

      printAccountTable(account->data, 8 + printed);
      printed++;

      account = account->next;
    }

    if (account == NULL && printed == 0) {
      changeForegroundColor(161, 161, 170);
      writeText("Nenhuma conta foi encontrada!", SCREEN_WIDTH / 2,
                SCREEN_HEIGHT / 2, 0);
      setDefaultColor();
    }

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    writeText("Pressione 'Enter' para continuar: ", 0, SCREEN_HEIGHT - 1, 0);
    continueListing = awaitPressAnyKey(0);
    if (noAccounts)
      continueListing = 'b';
    else
      page++;
  } while (continueListing != 'b');
}