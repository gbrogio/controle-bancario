#include "../global.h"
#include <stdio.h>
#include <string.h>

void trimString(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove o '\n' se presente
    }
}

void getInput(char mask[], GenericType input, int size, char err[], int x, int y,
              int validation(GenericType i, GenericType a), GenericType args) {
  int hasError;
  int validationResult;
  do {
    for (int i = 0; i < SCREEN_WIDTH - x - 2; i++) {
      goTo(x + i, y);
      printf(" ");
    }
    clearFooter();

    goTo(x, y);
    if (strcmp(mask, "%s") == 0) {
      fgets((char *)input, size, stdin);
      trimString((char *)input);
      hasError = 1;
    } else {
      hasError = scanf(mask, input);
      clearInputBuffer();
    }
    validationResult = validation(input, args);
    if (hasError != 1 || validationResult == 1) {
      printMessage(err, 0);
      continue;
    }
  } while (hasError != 1 || validationResult == 1);
}