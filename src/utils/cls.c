#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../global.h"


void cls() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}