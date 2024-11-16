#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"

char confirm(char msg[])
{
  char c;
  do
  {
    clearFooter();
    writeText(msg, 0, SCREEN_HEIGHT - 1, 0);
    writeText("(S/N) ", strlen(msg) + 3, SCREEN_HEIGHT - 1, 1);
    scanf("%c", &c);
    if (c != 's' && c != 'n')
    {
      writeText("Entrada invalida! Digite 's' para sim ou 'n' para nao.", 0, SCREEN_HEIGHT - 1, 0);
      awaitPressAnyKey(0);
    }
  } while (c != 's' && c != 'n');
  return c;
}