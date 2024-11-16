#include <stddef.h>
#include <stdlib.h>

#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void removeAccountByNumber(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 14,
              SCREEN_HEIGHT / 2, 0);

    char number[8];
    int position = 0;

    getInput("%s", number,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, list);

    if (number[0] == '0') {
      clearFooter();
      doAgain = confirm("Deseja remover outra conta?");
      continue;
    }

    position = findAccountPosition(list, number);

    if (position == -1)
    {
      printMessage("Conta nao encontrada! Pressione 'Enter' para continuar...");
      continue;
    }

    cls();
    buildScreen();
    writeText("REMOVER CONTA", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, position);
    clearFooter();
    char confirmation = confirm("Deseja remover essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      if (position == 0)
      {
        AccountListItemPointer firstAccount = list->head;
        list->head = list->head->next;
        free(firstAccount);
      }
      else
      {
        AccountListItemPointer previousAccount = list->head;
        for (int i = 0; i < position - 1; i++)
        {
          previousAccount = previousAccount->next;
        }
        AccountListItemPointer currentAccount = previousAccount->next;
        previousAccount->next = currentAccount->next;
        free(currentAccount);
      }

      list->length--;
    }

    clearFooter();
    doAgain = confirm("Deseja remover outra conta?");
  } while (doAgain == 's');
}