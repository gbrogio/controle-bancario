/*
  Author: Guilherme Brogio Macedo da Silva <guilhermebrogio.ps@gmail.com>
  Date: 24/10/2024
  Description: Bank account management and transfer control program.
*/

// main libs
#include <locale.h>

#include "functions/functions.h"
#include "global.h"
#include "screens/screens.h"

int main() {
  AccountList *accountList = initializeAccountList();
  TransactionList *transactionList = initializeTransactionList();

  setlocale(LC_ALL, "Portuguese");
  int start = 0;
  char c = '0';

  do {
    if ((c == '0' || c == 'b') && start == 0) {
      homeScreen();
    } else if (c == 'h') {
      helpScreen();
      c = 'b';
      continue;
    }
    else if (c == 'x') break;
    else {
      start = 1;
      c = loginScreen(accountList, transactionList);
      if (c == 'b') c = '1';
      continue;
    }
    clearFooter();
    if (c == '0' || c == 'b') c = command();
  } while (c != 'x');

  return 0;
}
