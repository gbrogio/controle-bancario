#include <stdio.h>
#include <stdlib.h>
#include "../global.h"

void changeBackgroundColor(int r, int g, int b) {
  printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void changeForegroundColor(int r, int g, int b) {
  printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void setDefaultColor() {
  changeBackgroundColor(9, 9, 11);
  changeForegroundColor(250, 250, 250);
}