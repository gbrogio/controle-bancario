#ifndef GLOBAL_H
#define GLOBAL_H
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define APP_NAME "G.B.M.S. Bank"
#define ADM_CODE "123"
#define ADM_PASSWORD "123"

typedef void *GenericType;

void writeText(char *text, int x, int y, int disableProporcion);
char command();
void clearInputBuffer();
void getInput(char mask[], GenericType input, char err[], int x,
              int y, int validation(GenericType i, GenericType a), GenericType args);
void printMessage(char msg[]);
void clearFooter();
int noValid();
char confirm(char msg[]);
void goTo(int x, int y);
void cls();
char awaitPressAnyKey(int clearBuffer);

#endif