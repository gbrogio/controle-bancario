#include <stdio.h>
#include <stdlib.h>
#include "cls.h"

void cls() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
