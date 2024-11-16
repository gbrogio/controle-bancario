#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "functions.h"
#include "../models/transaction.h"
#include "../models/account.h"
#include "../validations/validations.h"
#include "../global.h"

Transaction createTransaction(TransactionList *list, AccountListItem *account, char type)
{
  Transaction transaction;
  transaction.id = list->length + 1;

  writeText("VALOR TRANSACAO..:", 0, SCREEN_HEIGHT / 2, 4);
  getInput("%lf", &transaction.value, "Digite um valor valido! Pressione 'Enter' para reescrever...", 22, SCREEN_HEIGHT / 2, noValid, NULL);

  transaction.type = type;
  strcpy(transaction.accountNumber, account->data.number);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int ano = tm.tm_year + 1900;
  sprintf(transaction.movimentDate, "%02d/%02d/%04d as %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, ano, tm.tm_hour, tm.tm_min, tm.tm_sec);

  if (type == 'd')
    account->data.balance -= transaction.value;
  else
    account->data.balance += transaction.value;

  transaction.balance = account->data.balance;

  return transaction;
}