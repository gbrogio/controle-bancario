#include <stddef.h>
#include <stdlib.h>

#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void disableAccountByNumber(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("INATIVAR CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 14,
              SCREEN_HEIGHT / 2, 0);

    char number[8];
    int position = 0;

    getInput("%s", number,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, list);

    if (number[0] == '0') {
      clearFooter();
      doAgain = confirm("Deseja inativar outra conta?");
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
    writeText("inativar CONTA", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, position);
    clearFooter();
    char confirmation = confirm("Deseja inativar essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      if (position == 0)
      {
        AccountListItemPointer firstAccount = list->head;
        strcpy(firstAccount->data.status, "inativo");
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
    doAgain = confirm("Deseja inativar outra conta?");
  } while (doAgain == 's');
}