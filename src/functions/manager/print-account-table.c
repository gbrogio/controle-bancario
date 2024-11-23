#include "../../global.h"
#include "../../models/account.h"
#include "../functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAccountTable(Account account, int y) {
  char statusUpper[5];

  if (strcmp(account.status, "ativo") == 0)
    strcpy(statusUpper, "ATI.");
  else
    strcpy(statusUpper, "INA.");

  goTo(2, y);
  printf("%.3s. |", statusUpper);

  goTo(9, y);
  printf("%.9s", account.bank);
  if (strlen(account.bank) > 9)
    printf("...");

  goTo(22, y);
  if (strlen(account.agency) == 5)
    printf("| %s    |", account.agency);
  else
    printf("| %s   |", account.agency);

  goTo(35, y);
  printf("%s   |", account.number);

  goTo(48, y);
  printf(" %c   |", toupper(account.type));

  goTo(55, y);
  printf("%.2lf", account.balance);

  goTo(65, y);
  printf("| %.2lf", account.limit);
}
