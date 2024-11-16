#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"

char command() {
  char c;
  clearFooter();
  writeText("COMANDO:", 0, SCREEN_HEIGHT - 1, 0);
  writeText("x - SAIR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
  goTo(11, SCREEN_HEIGHT - 1);
  do {
      scanf("%c", &c);
  } while (c == '\n');
  return tolower(c);
}