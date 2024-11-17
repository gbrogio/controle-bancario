#include <stdio.h>

#include "../global.h"

void clearFooter()
{
  for (int i = 0; i < SCREEN_WIDTH - 2; i++)
  {
    goTo(1 + i, SCREEN_HEIGHT - 1);
    printf(" ");
  }
}