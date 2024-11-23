#include "../../global.h"
#include "../../models/account.h"
#include "../../models/transaction.h"
#include "../functions.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void createYieldTransaction(TransactionList *transactionList, Account *account,
                            double yield) {
  Transaction transaction;
  transaction.id = transactionList->length + 1;
  transaction.type = 'y'; // Tipo de transação para rendimento
  transaction.value = yield;
  strcpy(transaction.toAccountNumber, account->number);
  strcpy(transaction.fromAccountNumber, YIELD_ACCOUNT_NUMBER);
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(transaction.movimentDate, "%02d/%02d/%04d as %02d:%02d:%02d",
          tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min,
          tm.tm_sec);
  transaction.balance = account->balance;

  pushTransaction(transactionList, transaction);
}

double giveYieldTo(AccountListItemPointer account,
                   TransactionList *transactionList) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int currentDay = tm.tm_mday;

  if (currentDay == account->data.interestDay && account->data.yielded == 0) {
    double yield = account->data.balance * YIELD;
    account->data.balance += yield;
    account->data.yielded = 1;
    createYieldTransaction(transactionList, &account->data, yield);
    return yield;
  }

  if (account->data.yielded == 1 && currentDay != account->data.interestDay) {
    account->data.yielded = 0;
  }
  return 0.0;
}