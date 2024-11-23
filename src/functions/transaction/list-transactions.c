#include "../../global.h"
#include "../../models/transaction.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <stdio.h>
#include <string.h>

void listTransactions(TransactionList *list, char number[]) {
  TransactionListItemPointer transaction = list->head;
  int page = 1;
  int noTransactions = 0;
  char option;
  clearInputBuffer();

  do {
    cls();
    buildScreen();
    writeText("LISTAR TRANSACOES", SCREEN_WIDTH / 2, 4, 0);
    writeText("DATA                   | TIPO      | VALOR (R$)  | CONTA      | "
              "SALDO F. (R$)",
              2, 5, 1);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
      goTo(i, 6);
      // printf("═");
      printf("-");
    }
    goTo(25, 6);
    printf("|");
    goTo(37, 6);
    printf("|");
    goTo(51, 6);
    printf("|");
    goTo(64, 6);
    printf("|");

    // corners
    goTo(0, 6);
    // printf("╠");
    printf("+");
    goTo(SCREEN_WIDTH, 6);
    // printf("╣");
    printf("+");

    int printed = 0;
    for (int i = page * 0; i < 17; i++) {
      if (transaction == NULL) {
        noTransactions = 1;
        break;
      }
      if (strcmp(transaction->data.fromAccountNumber, number) != 0 ||
          strcmp(transaction->data.toAccountNumber, number) != 0) {
        transaction = transaction->next;
        continue;
      }

      printTransaction(transaction->data, 7 + printed);
      printed++;

      transaction = transaction->next;
    }

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    writeText("Pressione 'Enter' para continuar: ", 0, SCREEN_HEIGHT - 1, 0);
    option = awaitPressAnyKey(0);
    if (noTransactions)
      option = 'b';
    else
      page++;
  } while (option != 'b');
}