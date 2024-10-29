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
    doAgain = confirm("Deseja cadastrar outro conta?");
  } while (doAgain == 's');
}

/*
    Register an account at the start of the list
    @param list The list of accounts
*/
void registerAccountAtStart(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    clearFooter();
    if (account.code != 0)
    {
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        unshiftAccount(list, account);
    }
    clearFooter();
    doAgain = confirm("Deseja cadastrar outro conta?");
  } while (doAgain == 's');
}

int invalidPosition(GenericType i, GenericType a)
{
  int position = *(int *)i;
  AccountList *list = (AccountList *)a;
  return position < 0 || position > list->length;
}

/*
    Register an account in a specific position in the list
    @param list The list of accounts
*/
void registerAccountAtPosition(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);

    writeText("Posicao..:", SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2, 0);
    int position;

    getInput("%d", &position,
             "Por favor digite uma posicao valida! Pressione 'Enter' para "
             "continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, invalidPosition, list);

    cls();
    buildScreen();
    writeText("CADASTRO DE CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);
    Account account = createAccount(list, 0, -1);
    clearFooter();
    if (account.code != 0)
    {
      char confirmation = confirm("Deseja cadastrar essa conta?");
      if (confirmation == 's')
        insertAccountIn(position, list, account);
    }

    clearFooter();
    doAgain = confirm("Deseja cadastrar outro conta?");
  } while (doAgain == 's');
}

/*
    Remove an account at the end of the list
    @param list The list of accounts
*/
void removeAccountAtEnd(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA (FINAL)", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, list->length - 1);
    clearFooter();
    char confirmation = confirm("Deseja remover essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      AccountListItemPointer lastAccount = list->tail;
      AccountListItemPointer previousAccount = list->head;

      for (int i = 0; i < list->length - 1; i++)
      {
        previousAccount = previousAccount->next;
      }
      list->tail = previousAccount;
      previousAccount->next = NULL;
      free(lastAccount);

      list->length--;
    }
    clearFooter();
    doAgain = confirm("Deseja remover outro conta?");
  } while (doAgain == 's');
}

/*
    Remove an account at the start of the list
    @param list The list of accounts
*/
void removeAccountAtStart(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA (INICIO)", SCREEN_WIDTH / 2, 4, 0);
    printAccountInPosition(list, 0);
    clearFooter();
    char confirmation = confirm("Deseja remover essa conta?");
    if (confirmation == 's')
    {
      if (list->head == NULL)
        return;
      AccountListItemPointer firstAccount = list->head;
      list->head = list->head->next;
      free(firstAccount);
      list->length--;
    }
    clearFooter();
    doAgain = confirm("Deseja remover outro conta?");
  } while (doAgain == 's');
}

/*
    Remove an account in a specific position in the list
    @param list The list of accounts
*/
void removeAccountAtPosition(AccountList *list)
{
  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("REMOVER CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);
    writeText("Posicao..:", SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2, 0);

    int position;
    getInput("%d", &position,
             "Por favor digite uma posicao valida! Pressione 'Enter' para "
             "continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, invalidPosition, list);

    cls();
    buildScreen();
    writeText("REMOVER CONTA (POSICAO)", SCREEN_WIDTH / 2, 4, 0);
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
    doAgain = confirm("Deseja remover outro conta?");
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
    writeText("ALTERAR CADASTRO DE conta", SCREEN_WIDTH / 2, 4, 0);

    writeText("Codigo do conta..:", SCREEN_WIDTH / 2 - 18,
              SCREEN_HEIGHT / 2, 0);

    int code;
    int position = 0;

    getInput("%d", &code,
             "Digite um codigo valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationCode, list);

    cls();
    buildScreen();
    writeText("ALTERAR CADASTRO DE conta", SCREEN_WIDTH / 2, 4, 0);
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
          if (field < 1 || field > 7)
            printMessage("Por favor digite um numero entre 1 e 6!");
        } while (field < 1 || field > 7);

        Account newField = createAccount(list, 1, field);
        if (field == 1)
        {
          strcpy(account.bank, newField.bank);
        }
        else if (field == 2)
        {
          strcpy(account.agency, newField.agency);
        }
        else if (field == 3)
        {
          strcpy(account.number, newField.number);
        }
        else if (field == 4)
        {
          account.type = newField.type;
        }
        else if (field == 5)
        {
          account.balance = newField.balance;
        }
        else if (field == 6)
        {
          account.limit = newField.limit;
        }
        else if (field == 7)
        {
          strcpy(account.status, newField.status);
        }

        clearFooter();
        alterAgain = confirm("Deseja alterar outro campo?");
      } while (alterAgain == 's');

      clearFooter();
      char confirmationModify = confirm("Deseja confirmar a alteracao?");
      if (confirmationModify == 's')
      {
        account.code = code;
        alterAccountInPostion(list, account, position);
      }
    }
    clearFooter();
    doAgain = confirm("Deseja alterar outro conta?");
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

  writeText("1 - Cadastrar conta no Final da Lista", 0, 6, 0);
  writeText("2 - Cadastrar conta no Inicio da Lista", 0, 7, 0);
  writeText("3 - Cadastrar conta em uma Posicao da Lista", 0, 8, 0);
  writeText("4 - Remover conta no Final da Lista", 0, 9, 0);
  writeText("5 - Remover conta no Inicio da Lista", 0, 10, 0);
  writeText("6 - Remover conta em uma Posicao da Lista", 0, 11, 0);
  writeText("7 - Alterar cadastro da conta", 0, 12, 0);
  writeText("8 - Consultar contas", 0, 13, 0);
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
    registerAccountAtStart(list);
    option = '0';
    return option;
  }

  if (option == '3')
  {
    registerAccountAtPosition(list);
    option = '0';
    return option;
  }

  if (option == '4')
  {
    removeAccountAtEnd(list);
    option = '0';
    return option;
  }

  if (option == '5')
  {
    removeAccountAtStart(list);
    option = '0';
    return option;
  }

  if (option == '6')
  {
    removeAccountAtPosition(list);
    option = '0';
    return option;
  }

  if (option == '7')
  {
    alterAccount(list);
    option = '0';
    return option;
  }

  if (option == '8')
  {
    listAccounts(list);
    option = '0';
    return option;
  }

  return option;
}
