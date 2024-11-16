#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"


void goTo(int x, int y)
{
  printf("\033[%d;%dH", y + 1, x + 1);
}