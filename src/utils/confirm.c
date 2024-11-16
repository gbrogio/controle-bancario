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
      printMessage("Entrada invalida! Digite 's' para Sim ou 'n' para Nao.");
    }
  } while (c != 's' && c != 'n');
  return c;
}