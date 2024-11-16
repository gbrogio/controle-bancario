#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}