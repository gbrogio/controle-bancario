#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"


void getInput(char mask[], GenericType input, char err[], int x,
              int y, int validation(GenericType i, GenericType a), GenericType args)
{
  int hasError;
  int validationResult;
  do
  {
    for (int i = 0; i < SCREEN_WIDTH - x - 2; i++)
    {
      goTo(x + i, y);
      printf(" ");
    }
    clearFooter();

    goTo(x, y);

    hasError = scanf(mask, input);
    validationResult = validation(input, args);
    if (hasError != 1 || validationResult == 1)
    {
      printMessage(err);
      continue;
    }
    clearInputBuffer();
  } while (hasError != 1 || validationResult == 1);
}