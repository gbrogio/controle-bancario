#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"

char awaitPressAnyKey(int clearBuffer) {
  char c;
  if (clearBuffer) clearInputBuffer();
  c = getchar();
  return tolower(c);
}