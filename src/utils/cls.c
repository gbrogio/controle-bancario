#include "../global.h"
#include <stdlib.h>

void cls() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}