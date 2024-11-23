/*
  Author: Guilherme Brogio Macedo da Silva <guilhermebrogio.ps@gmail.com>
  Date: 24/10/2024
  Description: Bank account management and transfer control program.
*/

// main libs
#include "functions/functions.h"
#include "global.h"
#include "screens/screens.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  AccountList *accountList = initializeAccountList();
  TransactionList *transactionList = initializeTransactionList();
  loadAccounts(accountList, "db/accounts.dat");
  loadTransactions(transactionList, "db/transactions.dat");

  system("echo -e \"\033[48;2;9;9;11m\033[38;2;250;250;250m\"");
  setlocale(LC_ALL, "Portuguese");

  int start = 0;
  char c = '0';

  AccountListItemPointer account = accountList->head;
  while (account != NULL) {
    if (account->data.type == 'p' && account->data.balance > 0) {
      giveYieldTo(account, transactionList);
    }
    account = account->next;
  }

  do {
    if ((c == '0' || c == 'b') && start == 0) {
      homeScreen();
    } else if (c == 'h') {
      helpScreen();
      c = 'b';
      continue;
    } else if (c == 'x')
      break;
    else {
      start = 1;
      c = loginScreen(accountList, transactionList);
      if (c == 'b')
        c = '1';
      continue;
    }
    clearFooter();
    if (c == '0' || c == 'b')
      c = command();
  } while (c != 'x');

  saveAccounts(accountList, "db/accounts.dat");
  saveTransactions(transactionList, "db/transactions.dat");

  clearFooter();
  goTo(2, SCREEN_HEIGHT - 1);
  printf("Dados salvos com sucesso em /db/**.dat\n");

  goTo(SCREEN_WIDTH * 2, SCREEN_HEIGHT + 1);
  return 0;
}
