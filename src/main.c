/*
  Author: Guilherme Brogio Macedo da Silva <guilhermebrogio.ps@gmail.com>
  Date: 24/10/2024
  Description: Bank account management and transfer control program.
*/

// main libs
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "functions/functions.h"
#include "screens/screens.h"

int main() {
  AccountList *list = initializeAccountList();

  setlocale(LC_ALL, "Portuguese");
  int start = 0;
  char c = '0';

  do {
    if ((c == '0' || c == 'b') && start == 0) {
      mainScreen();
    } else if (c == 'h') {
      helpScreen();
      c = 'b';
      continue;
    }
    else if (c == 'x') break;
    else {
      start = 1;
      c = loginScreen(list);
      if (c == 'b') c = '1';
      continue;
    }
    clearFooter();
    if (c == '0' || c == 'b') c = command();
  } while (c != 'x');

  return 0;
}
