#include "../global.h"
#include "../models/account.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void loadTransactions(TransactionList *list, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    clearFooter();
    goTo(2, SCREEN_HEIGHT - 1);
    perror("Erro ao abrir o arquivo para leitura");
    return;
  }

  Transaction transaction;
  while (fread(&transaction, sizeof(Transaction), 1, file)) {
    pushTransaction(list, transaction);
  }

  fclose(file);
}

void saveTransactions(TransactionList *list, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    clearFooter();
    goTo(2, SCREEN_HEIGHT - 1);
    perror("Erro ao abrir o arquivo para escrita");
    return;
  }

  TransactionListItemPointer transaction = list->head;
  while (transaction != NULL) {
    size_t written = fwrite(&transaction->data, sizeof(Transaction), 1, file);
    if (written != 1) {
      clearFooter();
      goTo(2, SCREEN_HEIGHT - 1);
      perror("Erro ao escrever no arquivo");
      fclose(file);
      return;
    }
    TransactionListItemPointer toFree = transaction;
    transaction = transaction->next;
    free(toFree);
  }

  fclose(file);
  clearFooter();
  goTo(2, SCREEN_HEIGHT - 1);
  printf("Transacoes salvas com sucesso em %s\n", filename);
}
