#include "../global.h"

void printMessage(char msg[], int clearBuffer) {
  writeText(msg, 0, SCREEN_HEIGHT - 1, 0);
  awaitPressAnyKey(clearBuffer);
}