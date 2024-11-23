#include "../../global.h"
#include "../../models/transaction.h"
#include "../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTransaction(Transaction transaction, int y) {
  char type[10];
  switch (transaction.type) {
  case 'd':
    strcpy(type, "DEBITO ");
    break;
  case 'c':
    strcpy(type, "CREDITO");
    break;
  }

  goTo(2, y);
  printf("%s |", transaction.movimentDate);

  goTo(27, y);
  printf("%s   |", type);

  goTo(39, y);
  printf("%.2lf", transaction.value);

  goTo(51, y);
  printf("| %s   | %.2lf",
         transaction.type == 'c' ? transaction.fromAccountNumber
                                 : transaction.toAccountNumber,
         transaction.balance);
}
