#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void listAccounts(AccountList *list)
{
  AccountListItemPointer account = list->head;
  clearInputBuffer();
  for (int i = 0; i < list->length; i++)
  {
    cls();
    buildScreen();
    writeText("LISTAR CONTAS", SCREEN_WIDTH / 2, 4, 0);

    printAccount(account->data);

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    writeText("Pressione 'Enter' para continuar: ", 0, SCREEN_HEIGHT - 1,
              0);

    char option = awaitPressAnyKey(0);
    if (option == 'b')
      break;

    account = account->next;
  }
}