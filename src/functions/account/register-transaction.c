#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../global.h"
#include "../../models/account.h"
#include "../functions.h"

void registerTransaction(TransactionList *list, AccountListItem *account,
                         char type, int insertDate) {
  char doAgain = 's';
  do {
    cls();
    buildScreen();
    writeText("REGISTRAR ", SCREEN_WIDTH / 2, 4, 0);
    printf(type == 'c' ? "ENTRADA" : "SAIDA");

    AccountListItem from = *account;
    Transaction transaction =
        createTransaction(list, &from, &from, type, insertDate);

    if (transaction.value != 0) {
      clearFooter();
      char confirmation = confirm("Deseja confirmar essa transacao?");
      if (confirmation == 's') {
        pushTransaction(list, transaction);
        account->data = from.data;
      }
    }
    clearFooter();
    doAgain = confirm("Deseja realizar outra transacao?");
  } while (doAgain == 's');
}
