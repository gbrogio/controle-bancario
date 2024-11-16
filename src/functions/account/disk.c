#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"
#include "../../models/account.h"

void loadAccounts(AccountList *list, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) return;

  Account account;
  while (fread(&account, sizeof(Account), 1, file)) {
    pushAccount(list, account);
  }

  fclose(file);
}

void saveAccounts(AccountList *list, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) return;

  AccountListItemPointer account = list->head;
  while (account != NULL) {
    fwrite(&account->data, sizeof(Account), 1, file);
    AccountListItemPointer toFree = account;
    account = account->next;
    free(toFree);
  }

  fclose(file);
}
