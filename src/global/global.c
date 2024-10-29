#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "global.h"


/* Clear the terminal */
void cls() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char command() {
  char c;
  clearFooter();
  writeText("COMANDO:", 0, SCREEN_HEIGHT - 1, 0);
  writeText("x - SAIR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
  goTo(11, SCREEN_HEIGHT - 1);
  do {
      scanf("%c", &c);
  } while (c == '\n');
  return tolower(c);
}

void writeText(char *text, int x, int y, int disableProporcion)
{
  if (text == NULL)
  {
    fprintf(stderr, "Error: null text passed to writeText\n");
    return;
  }

  if (SCREEN_WIDTH == 0)
  {
    fprintf(stderr, "Erro: SCREEN_WIDTH is zero\n");
    return;
  }

  // add padding left
  int x_correct;
  if (x == 0)
    x_correct = 2;
  else
    x_correct = x;

  // use to know where the text will start
  float proporcion = (double)x / SCREEN_WIDTH;
  float length = strlen(text) * proporcion;

  /*
    correct the x position if the text is bigger than the screen width
    and add padding right. else, pass the x position minus the text length
    proporcionalized (like: length = 10, but the x was the middle of the screen,
    so the correct length to substract is 5).
  */
  int poss_correct;
  if (length + x_correct > SCREEN_WIDTH - 1)
  {
    poss_correct = (x_correct - ((length + x_correct) - (SCREEN_WIDTH - 1)));
  }
  else
    poss_correct = x_correct - length;

  if (disableProporcion == 1)
    poss_correct = x;

  goTo(poss_correct, y);
  printf("%s", text);
}

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n')
    ;
}

int noValid() {
  return 0;
}

/* Clear the footer of the terminal */
void clearFooter()
{
  for (int i = 0; i < SCREEN_WIDTH - 4; i++)
  {
    goTo(2 + i, SCREEN_HEIGHT - 1);
    printf(" ");
  }
}

/*
    Print an error message on the footer of the terminal
    @param err The error message to be displayed
*/
void printMessage(char msg[]) { 
  writeText(msg, 0, SCREEN_HEIGHT - 1, 0);
  awaitPressAnyKey(1);
}

/*
  Utilitary function to get an input from user and validate if user typed a
  number in char format or etc.
  @param mask The mask to be used on `scanf`
  @param input The input to be stored
  @param err The error message to be displayed if the input is invalid
  @param x The x position on terminal
  @param y The y position on terminal

  @example
  int input;
  getInput("%d", &input, "Por favor digite um numero valido", 0, 0, noValid, NULL;
*/
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

/*
  Confirm a message with a 'S' or 'N' input
  @param msg The message to be displayed
  @return The input of the user
*/
char confirm(char msg[]) {
    char c;
    writeText(msg, 0, SCREEN_HEIGHT - 1, 0);
    writeText("(S/N)", strlen(msg) + 3, SCREEN_HEIGHT - 1, 1);
    do {
        goTo(strlen(msg) + 9, SCREEN_HEIGHT - 1);
        scanf("%c", &c);
    } while (c == '\n');
    return tolower(c);
}

/*
  Go to a specific position on the terminal
  @param x The x position
  @param y The y position
*/
void goTo(int x, int y)
{
  printf("\033[%d;%dH", y + 1, x + 1);
}

/*
  Await for the user to press any key
*/
char awaitPressAnyKey(int clearBuffer) {
  char c;
  if (clearBuffer) clearInputBuffer();
  c = getchar();
  return tolower(c);
}
