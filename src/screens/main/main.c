#include "main.h"
#include "../../global/global.h"
#include "../../utils/screen/screen.h"
#include "../../utils/cls/cls.h"

void mainScreen() {
  cls();
  writeText("APP DESCRIPTION", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1, 0);
  writeText("digit any key to execute the app.", SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 1, 0);
  writeText("or press \"h\" to enter on help page.", SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 2, 0);
  buildScreen();
}