#include "../../global.h"
#include "../../models/account.h"
#include "../../models/transaction.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Transaction createTransaction(TransactionList *list, AccountListItem *from,
                              AccountListItem *to, char type, int insertDate) {
  if (to == NULL)
    to = from;

  Transaction transaction;
  transaction.id = list->length + 1;
  writeText("VALOR TRANSACAO..:", SCREEN_WIDTH / 2 - 14, SCREEN_HEIGHT / 2, 4);
  if (insertDate)
    writeText("DATA.............:", SCREEN_WIDTH / 2 - 14,
              SCREEN_HEIGHT / 2 + 1, 4);

  do {
    getInput("%lf", &transaction.value, 0,
             "Digite um valor valido! Pressione 'Enter' para reescrever...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, noValid, NULL);

    if (from->data.balance + from->data.limit < transaction.value &&
        type == 'd') {
      printMessage("Saldo insuficiente! Pressione 'Enter' para continuar...",
                   0);
    }
  } while (from->data.balance + from->data.limit < transaction.value &&
           type == 'd');

  char dateFormated[12];
  if (insertDate) {
    do {
      getInput("%s", dateFormated, 12,
               "Digite uma data valida (ex. dd/mm/aaaa)! Pressione 'Enter' "
               "para reescrever...",
               SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 1, validationDate, NULL);

      if (list->tail == NULL)
        break;

      char dateString[10] = {dateFormated[6], dateFormated[7], dateFormated[8],
                             dateFormated[9], dateFormated[3], dateFormated[4],
                             dateFormated[0], dateFormated[1], '\0'};
      int currentDate = atoi(dateString);

      char dateList[10] = {list->tail->data.movimentDate[6],
                           list->tail->data.movimentDate[7],
                           list->tail->data.movimentDate[8],
                           list->tail->data.movimentDate[9],
                           list->tail->data.movimentDate[3],
                           list->tail->data.movimentDate[4],
                           list->tail->data.movimentDate[0],
                           list->tail->data.movimentDate[1],
                           '\0'};
      int lastDate = atoi(dateList);

      if (currentDate < lastDate) {
        printMessage("Data invalida! Pressione 'Enter' para continuar...", 0);
        continue;
      }

      break;
    } while (1);
  }

  transaction.type = type;
  strcpy(transaction.toAccountNumber, to->data.number);
  strcpy(transaction.fromAccountNumber, from->data.number);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  if (insertDate) {
    sprintf(transaction.movimentDate, "%s as %02d:%02d:%02d", dateFormated,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
  } else {
    int year = tm.tm_year + 1900;
    sprintf(transaction.movimentDate, "%02d/%02d/%04d as %02d:%02d:%02d",
            tm.tm_mday, tm.tm_mon + 1, year, tm.tm_hour, tm.tm_min, tm.tm_sec);
  }

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