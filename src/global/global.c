#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "global.h"
#include "../utils/go-to/go-to.h"

char command() {
  char c[2];
  writeText("COMMAND:", 0, SCREEN_HEIGHT - 1, 0);
  writeText("x - EXIT", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
  goTo(11, SCREEN_HEIGHT - 1);
  scanf(" %1s", c);
  getchar();
  return tolower(c[0]);
}

void writeText(char *text, int x, int y, int disableProporcion) {
  if (text == NULL) {
    fprintf(stderr, "Error: null text passed to writeText\n");
    return;
  }

  if (SCREEN_WIDTH == 0) {
    fprintf(stderr, "Erro: SCREEN_WIDTH is zero\n");
    return;
  }

  // add padding left
  int x_correct;
  if (x == 0) x_correct = 2;
  else x_correct = x;

  // use to know where the text will start
  float proporcion = (double) x / SCREEN_WIDTH;
  float length = strlen(text)  * proporcion;

  /* 
    correct the x position if the text is bigger than the screen width
    and add padding right. else, pass the x position minus the text length
    proporcionalized (like: length = 10, but the x was the middle of the screen,
    so the correct length to substract is 5).
  */
  int poss_correct;
  if (length + x_correct > SCREEN_WIDTH - 1) {
    poss_correct = (x_correct - ((length + x_correct) - (SCREEN_WIDTH - 1)));
  } else poss_correct = x_correct - length;

  if (disableProporcion == 1) poss_correct = x;

  goTo(poss_correct, y);
  printf("%s", text);
}


void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n');
}
