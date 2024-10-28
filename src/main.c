/*
  Author: Guilherme Brogio Macedo da Silva <guilhermebrogio.ps@gmail.com>
  Date: 24/10/2024
  Description: Bank account management and transfer control program.
*/

// main libs
#include <stdio.h>
#include <locale.h>
#include <string.h>

// utils
#include "utils/screen/screen.h"

// global
#include "global/global.h"

// screens
#include "screens/help/help.h"
#include "screens/main/main.h"
#include "screens/login/login.h"
#include "utils/account/account.h"

int main() {
  AccountList *list = initializeAccountList();

  setlocale(LC_ALL, "Portuguese");
  int start = 0;
  char c;

  do {
    if ((!c || c == 'b') && start == 0) mainScreen();
    else if (c == 'h') {
      helpScreen();
      c = 'b';
      continue;
    }
    else if (c == 'x') break;
    else {
      start = 1;
      c = loginScreen(list);
      if (c == 'b') c = '0';
      continue;
    }
    clearFooter();
    if (!c || c == 'b') c = command();
  } while (c != 'x');

  return 0;
}
