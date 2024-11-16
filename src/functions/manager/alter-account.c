#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void alterAccount(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("ALTERAR CADASTRO DE CONTA", SCREEN_WIDTH / 2, 4, 0);

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
    writeText("ALTERAR CADASTRO DE CONTA", SCREEN_WIDTH / 2, 4, 0);


    Account account = printAccountInPosition(list, position);
    char confirmation = confirm("Deseja alterar essa conta?");
    if (confirmation == 's')
    {
      char alterAgain = 'n';
      do
      {
        int field;
        do
        {
          clearFooter();
          writeText("Qual campo voce deseja alterar?", 0,
                    SCREEN_HEIGHT - 1, 0);
          goTo(35, SCREEN_HEIGHT - 1);
          scanf("%d", &field);
          if (field < 1 || field > 8)
            printMessage("Por favor digite um numero valido e entre 1 e 8!");
        } while (field < 1 || field > 9 || (account.type == 'c' && field == 8) || (account.type == 'p' && field == 6));

        if (field == 4) clearInputBuffer();          
        Account newField = createAccount(list, 1, field);
        if (field == 1)
          strcpy(account.bank, newField.bank);
        else if (field == 2)
          strcpy(account.agency, newField.agency);
        else if (field == 3)
          strcpy(account.number, newField.number);
        else if (field == 4)
          account.type = newField.type;
        else if (field == 5)
          account.balance = newField.balance;
        else if (field == 6)
          account.limit = newField.limit;
        else if (field == 7)
          strcpy(account.status, newField.status);
        else if (field == 8)
          account.interestDay = newField.interestDay;
        else if (field == 9)
          strcpy(account.password, newField.password);

        if (account.type == 'c') {
          account.interestDay = 0;
          writeText("N/A", SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1, 1);
        }

        if (account.type == 'p') { 
          account.limit = 0;
          if (account.balance < 0) {
            account.balance = 0;
            writeText("0.00", 17, 16, 1);
          }
          writeText("N/A                 ", 17, 18, 1);
          account.interestDay = 1;
          writeText("1  ", SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1, 1);
        }

        clearFooter();
        alterAgain = confirm("Deseja alterar outro campo?");
      } while (alterAgain == 's');

      clearFooter();
      char confirmationModify = confirm("Deseja confirmar a alteracao?");
      if (confirmationModify == 's')
      {
        alterAccountInPostion(list, account, position);
      }
    }
    clearFooter();
    doAgain = confirm("Deseja alterar outra conta?");
  } while (doAgain == 's');
}