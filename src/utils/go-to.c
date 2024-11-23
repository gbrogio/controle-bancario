#include "../global.h"
#include <stdio.h>

void goTo(int x, int y) { printf("\033[%d;%dH", y + 2, x + 4); }