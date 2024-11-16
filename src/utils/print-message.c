




#include "../global.h"

void printMessage(char msg[]) { 
  writeText(msg, 0, SCREEN_HEIGHT - 1, 0);
  awaitPressAnyKey(1);
}