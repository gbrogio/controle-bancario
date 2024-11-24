#include "../global.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char confirm(char msg[]) {
  char c;
  do {
    clearFooter();
    writeText(msg, 0, SCREEN_HEIGHT - 1, 0);
    writeText("(S/N) ", strlen(msg) + 3, SCREEN_HEIGHT - 1, 1);
    scanf(" %c", &c);
    goTo(0, 0);
    c = tolower(c);
    if (c != 's' && c != 'n') {
      printMessage("Entrada invalida! Digite 's' para sim ou 'n' para nao.", 1);
    }
  } while (c != 's' && c != 'n');
  return c;
}