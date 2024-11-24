#include "../global.h"
#include <ctype.h>
#include <stdio.h>

char command() {
  char c;
  clearFooter();
  writeText("COMANDO:", 0, SCREEN_HEIGHT - 1, 0);
  changeForegroundColor(220, 38, 38);
  writeText("x - SAIR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
  setDefaultColor();
  goTo(11, SCREEN_HEIGHT - 1);
  do {
    scanf(" %c", &c);
  } while (c == '\n');

  return tolower(c);
}