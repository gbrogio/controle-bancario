#include <ctype.h>
#include <stdio.h>



#include "../global.h"

char awaitPressAnyKey(int clearBuffer) {
  char c;
  if (clearBuffer) clearInputBuffer();
  c = getchar();
  return tolower(c);
}