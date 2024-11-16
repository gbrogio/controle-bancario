#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"

void clearFooter()
{
  for (int i = 0; i < SCREEN_WIDTH - 4; i++)
  {
    goTo(2 + i, SCREEN_HEIGHT - 1);
    printf(" ");
  }
}