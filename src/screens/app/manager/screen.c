#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../global/global.h"
#include "../../../utils/screen/screen.h"
#include "./screen.h"
#include "../../../utils/account/account.h"

/*
    Register an account at the end of the list
    @param list The list of accounts
*/
void registerAccountAtEnd(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    clearFooter();
    if (account.code != 0)
    {
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        pushAccount(list, account);
    }
    clearFooter();
    doAgain = confirm("Deseja cadastrar outra conta?");
  } while (doAgain == 's');
}

/*
    Remove an account in a specific position in the list
    @param list The list of accounts
*/
void removeAccountByNumber(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 18,
              SCREEN_HEIGHT / 2, 0);

    char number[8];
    int position = 0;

    getInput("%s", number,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, list);
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

/*
    Alter an account in the list
    @param list The list of accounts
*/
void alterAccount(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("ALTERAR CADASTRO DE CONTA", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 18,
              SCREEN_HEIGHT / 2, 0);

    char number[8];
    int position = 0;

    getInput("%s", number,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, list);
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

/*
    AccountList all accounts in the list
    @param list The list of accounts
*/
void listAccounts(AccountList *list)
{
  AccountListItemPointer account = list->head;
  clearInputBuffer();
  for (int i = 0; i < list->length; i++)
  {
    cls();
    buildScreen();
    writeText("LISTAR CONTAS", SCREEN_WIDTH / 2, 4, 0);

    printAccount(account->data);

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    writeText("Pressione 'Enter' para continuar: ", 0, SCREEN_HEIGHT - 1,
              0);

    char option = awaitPressAnyKey(0);
    if (option == 'b')
      break;

    account = account->next;
  }
}

char managerScreen(AccountList *list)
{
  char option;
  cls();
  writeText("BEM VINDO DE VOLTA!", SCREEN_WIDTH, 4, 0);
  writeText("Entrou como: GERENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("b - Voltar para a tela de login", SCREEN_WIDTH, SCREEN_HEIGHT - 3, 0);

  writeText("1 - Cadastrar conta", 0, 6, 0);
  writeText("2 - Remover conta", 0, 8, 0);
  writeText("3 - Alterar cadastro da conta", 0, 10, 0);
  writeText("4 - Consultar contas", 0, 12, 0);
  buildScreen();

  option = command();

  if (option == '1')
  {
    registerAccountAtEnd(list);
    option = '0';
    return option;
  }

  if (option == '2')
  {
    removeAccountByNumber(list);
    option = '0';
    return option;
  }

  if (option == '3')
  {
    alterAccount(list);
    option = '0';
    return option;
  }

  if (option == '4')
  {
    listAccounts(list);
    option = '0';
    return option;
  }

  return option;
}
