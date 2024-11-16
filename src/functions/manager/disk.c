#include <stdio.h>
#include <stdlib.h>

#include "../functions.h"
#include "../../models/account.h"

void loadTransactions(TransactionList *list, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) return;

  Transaction transaction;
  while (fread(&transaction, sizeof(Transaction), 1, file)) {
    pushTransaction(list, transaction);
  }

  fclose(file);
}

void saveTransactions(TransactionList *list, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) return;

  TransactionListItemPointer transaction = list->head;
  while (transaction != NULL) {
    fwrite(&transaction->data, sizeof(Transaction), 1, file);
    TransactionListItemPointer toFree = transaction;
    transaction = transaction->next;
    free(toFree);
  }

  fclose(file);
}
