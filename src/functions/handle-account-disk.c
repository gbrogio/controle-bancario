#include "../global.h"
#include "../models/account.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void loadAccounts(AccountList *list, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    clearFooter();
    goTo(2, SCREEN_HEIGHT - 1);
    perror("Erro ao abrir o arquivo para leitura");
    return;
  }

  Account account;
  while (fread(&account, sizeof(Account), 1, file)) {
    pushAccount(list, account);
  }

  fclose(file);
}

void saveAccounts(AccountList *list, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    clearFooter();
    goTo(2, SCREEN_HEIGHT - 1);
    perror("Erro ao abrir o arquivo para escrita");
    return;
  }

  AccountListItemPointer account = list->head;
  while (account != NULL) {
    size_t written = fwrite(&account->data, sizeof(Account), 1, file);
    if (written != 1) {
      clearFooter();
      goTo(2, SCREEN_HEIGHT - 1);
      perror("Erro ao escrever no arquivo");
      fclose(file);
      return;
    }
    AccountListItemPointer toFree = account;
    account = account->next;
    free(toFree);
  }

  fclose(file);
  clearFooter();
  goTo(2, SCREEN_HEIGHT - 1);
  printf("Contas salvas com sucesso em %s\n", filename);
}
