#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"

void listAccounts(AccountList *list) {
  AccountListItemPointer account = list->head;
  clearInputBuffer();
  for (int i = 0; i < list->length; i++) {
    cls();
    buildScreen();
    writeText("LISTAR CONTAS", SCREEN_WIDTH / 2, 4, 0);

    printAccount(account->data, 0, 1);

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    writeText("Pressione 'Enter' para continuar: ", 0, SCREEN_HEIGHT - 1, 0);

    char option = awaitPressAnyKey(0);
    if (option == 'b')
      break;

    account = account->next;
  }
}