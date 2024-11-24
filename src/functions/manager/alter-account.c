#include "../../global.h"
#include "../../models/account.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alterAccountScreen(AccountList *list) {
  char doAgain = 's';
  do {
    cls();
    buildScreen();
    writeText("ALTERAR CADASTRO DE CONTA", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 14, SCREEN_HEIGHT / 2,
              0);

    char number[16];
    getchar();
    getInput("%s", number, 16,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, list);

    if (number[0] == '0') {
      clearFooter();
      doAgain = confirm("Deseja alterar outra conta?");
      continue;
    }

    GetAccountBy accountFounded = getAccountByNumber(list, number, 0);

    if (accountFounded.position == -1) {
      printMessage("Conta nao encontrada! Pressione 'Enter' para continuar...",
                   0);
      continue;
    }

    cls();
    buildScreen();
    writeText("ALTERAR CADASTRO DE CONTA", SCREEN_WIDTH / 2, 4, 0);

    printAccount(accountFounded.account->data, 0, 0);
    Account account = accountFounded.account->data;
    char confirmation = confirm("Deseja alterar essa conta?");
    if (confirmation == 's') {
      char alterAgain = 'n';
      do {
        int field;
        do {
          clearFooter();
          writeText("Qual campo voce deseja alterar?", 2, SCREEN_HEIGHT - 1, 1);
          getInput("%d", &field, 0,
             "Por favor digite um campo valido! Pressione 'Enter' para "
             "continuar...",
             35, SCREEN_HEIGHT - 1, noValid, list);

          if (field < 1 || field > 9)
            printMessage("Por favor digite um numero valido e entre 1 e 9!", 1);

          if (account.type == 'c' && field == 8)
            printMessage("Conta corrente nao possui dia de rendimentos!", 1);

          if (account.type == 'p' && field == 7)
            printMessage("Conta poupanca nao possui limite!", 1);
        } while (field < 1 || field > 9 ||
                 (account.type == 'c' && field == 8) ||
                 (account.type == 'p' && field == 7));

        Account newField = createAccount(list, 1, field);
        if (field == 1)
          strcpy(account.bank, newField.bank);
        else if (field == 2)
          strcpy(account.agency, newField.agency);
        else if (field == 3)
          strcpy(account.number, newField.number);
        else if (field == 4)
          account.type = newField.type;
        else if (field == 6) {
          if (newField.balance != 0 && strcmp(account.status, "inativo") == 0) {
            writeText("R$ 0.00        ", 17, 18, 1);
            printMessage("Conta com saldo diferente de zero! Pressione 'Enter' "
                         "para continuar...",
                         0);
            clearFooter();
            alterAgain = confirm("Deseja alterar outro campo?");
            continue;
          }
          account.balance = newField.balance;
        }
        else if (field == 7)
          account.limit = newField.limit;
        else if (field == 5) {
          if (account.balance != 0 && strcmp(newField.status, "inativo") == 0) {
            writeText("ativo  ", 17, 16, 1);
            printMessage("Conta com saldo diferente de zero! Pressione 'Enter' "
                         "para continuar...",
                         0);
            clearFooter();
            alterAgain = confirm("Deseja alterar outro campo?");
            continue;
          }
          strcpy(account.status, newField.status);
        } else if (field == 8)
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
      if (confirmationModify == 's') {
        alterAccount(accountFounded.account, account);
      }
    }
    clearFooter();
    clearInputBuffer();
    doAgain = confirm("Deseja alterar outra conta?");
  } while (doAgain == 's');
}