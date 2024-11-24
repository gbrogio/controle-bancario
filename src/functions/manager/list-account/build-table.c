#include "../../../global.h"
#include <stdio.h>

void buildTableAccount(int y) {
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    goTo(i, y - 2);
    // printf("═");
    printf("-");
  }
  // corners
  goTo(0, y - 2);
  // printf("╠");
  printf("+");
  goTo(SCREEN_WIDTH, y - 2);
  // printf("╣");
  printf("+");

  writeText("ST.  | BANCO        | AGENCIA | CONTA      | TIPO | SALDO"
            "(R$) | LIMITE (R$)",
            2, y - 1, 1);

  for (int i = 0; i < SCREEN_WIDTH; i++) {
    goTo(i, y);
    // printf("═");
    printf("-");
  }

  // corners
  goTo(0, y);
  // printf("╠");
  printf("+");
  goTo(SCREEN_WIDTH, y);
  // printf("╣");
  printf("+");
}