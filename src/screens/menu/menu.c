#include "menu.h"
#include "../../global/global.h"
#include "../../utils/screen/screen.h"
#include "../../utils/cls/cls.h"

char menuScreen() {
  char option;
  cls();
  writeText("Menu:", SCREEN_WIDTH / 2, 4, 0);
  writeText("What you want?", 0, 6, 0);
  writeText("1 - Edit Here", 0, 11, 0);
  buildScreen();

  option = command();
  
  if (option == '1') {
    // function();
    option = 'b';
    return option;
  } 
  
  return option;
}