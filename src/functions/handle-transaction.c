#include "../global.h"
#include "../models/account.h"
#include "../models/transaction.h"
#include "../validations/validations.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

Transaction createTransaction(TransactionList *list, AccountListItem *from,
                              AccountListItem *to, char type) {
  if (to == NULL)
    to = from;

  Transaction transaction;
  transaction.id = list->length + 1;

  do {
    writeText("VALOR TRANSACAO..:", 0, SCREEN_HEIGHT / 2, 4);
    getInput("%lf", &transaction.value,
             "Digite um valor valido! Pressione 'Enter' para reescrever...", 22,
             SCREEN_HEIGHT / 2, noValid, NULL);

    if (from->data.balance + from->data.limit < transaction.value &&
        type == 'd') {
      printMessage("Saldo insuficiente! Pressione 'Enter' para continuar...",
                   1);
    }
  } while (from->data.balance + from->data.limit < transaction.value &&
           type == 'd');

  transaction.type = type;
  strcpy(transaction.toAccountNumber, to->data.number);
  strcpy(transaction.fromAccountNumber, from->data.number);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int ano = tm.tm_year + 1900;
  sprintf(transaction.movimentDate, "%02d/%02d/%04d as %02d:%02d:%02d",
          tm.tm_mday, tm.tm_mon + 1, ano, tm.tm_hour, tm.tm_min, tm.tm_sec);

  if (type == 'd') {
    from->data.balance -= transaction.value;
    if (to->data.code != from->data.code)
      to->data.balance += transaction.value;
  } else {
    if (to->data.code != from->data.code)
      to->data.balance -= transaction.value;
    from->data.balance += transaction.value;
  }

  transaction.balance = from->data.balance;

  return transaction;
}