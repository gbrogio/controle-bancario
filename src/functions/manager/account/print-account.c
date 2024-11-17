
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../../models/account.h"
#include "../../../global.h"

void printAccount(Account account)
{
  writeText("    CODIGO..:", 0, 6, 0);
  writeText("1 - BANCO...:", 0, 8, 0);
  writeText("2 - AGENCIA.:", 0, 10, 0);
  writeText("3 - NUMERO..:", 0, 12, 0);
  writeText("4 - TIPO....:", 0, 14, 0);
  writeText("5 - SALDO...:", 0, 16, 0);
  writeText("6 - LIMITE..:", 0, 18, 0);
  writeText("7 - STATUS..:", 0, 20, 0);
  writeText("8 - DIA RENDIMENTOS:", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1, 1);
  writeText("9 - SENHA..........:  ********", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 1, 1);

  goTo(17, 6);
  printf("%d", account.code);
  goTo(17, 8);
  puts(account.bank);
  goTo(17, 10);
  puts(account.agency);
  goTo(17, 12);
  puts(account.number);
  goTo(17, 14);
  if (account.type == 'c')
    puts("Conta Corrente");
  else
    puts("Conta Poupanca");
  goTo(17, 16);
  printf("%.2f", account.balance);
  goTo(17, 18);
  if (account.type == 'p')
    puts("N/A");
  else
    printf("%.2f", account.limit);
  goTo(17, 20);
  puts(account.status);
  goTo(SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1);
  if (account.type == 'c')
    puts("N/A");
  else
    printf("%d", account.interestDay);
}
