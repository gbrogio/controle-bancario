#ifndef GLOBAL_H
#define GLOBAL_H
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define APP_NAME "G.B.M.S. Bank"

void writeText(char* text, int x, int y, int disableProporcion);
char command();
void clearInputBuffer();

#endif