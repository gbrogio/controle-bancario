#include "../global.h"
#include <ctype.h>
#include <stdio.h>

char awaitPressAnyKey(int clearBuffer) {
  char c;
  if (clearBuffer)
    clearInputBuffer();
  c = getchar();
  return tolower(c);
}