#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./account.h"
#include "../../global/global.h"

void pushAccount(AccountList *list, Account data)
{
  AccountListItemPointer newData = (AccountListItemPointer)malloc(sizeof(AccountListItem));

  newData->data = data;
  newData->next = NULL;

  if (list->head == NULL)
    list->head = newData;
  else
    list->tail->next = newData;

  list->tail = newData;
  list->length++;
}

void alterAccountInPostion(AccountList *list, Account account, int position)
{
  if (list->head == NULL || position < 0 || position > list->length)
    return;

  AccountListItemPointer currentData = list->head;

  for (int i = 0; i < position; i++)
  {
    currentData = currentData->next;
  }

  strcpy(currentData->data.bank, account.bank);
  strcpy(currentData->data.agency, account.agency);
  strcpy(currentData->data.number, account.number);
  strcpy(currentData->data.status, account.status);
  strcpy(currentData->data.password, account.password);
  currentData->data.type = account.type;
  currentData->data.balance = account.balance;
  currentData->data.limit = account.limit;
  currentData->data.interestDay = account.interestDay;
}

int findAccountPosition(AccountList *list, char number[])
{
  if (list->head == NULL)
    return -1;

  AccountListItemPointer currentData = list->head;
  int position = 0;

  while (currentData != NULL)
  {
    if (strcmp(currentData->data.number, number) == 0)
      return position;
    currentData = currentData->next;
    position++;
  }

  return -1;
}

Account getAccountByNumber(AccountList *list, char number[])
{
  if (list->head == NULL)
  {
    Account emptyAccount;
    emptyAccount.code = -1;
    return emptyAccount;
  }

  AccountListItemPointer currentData = list->head;

  while (currentData != NULL)
  {
    if (strcmp(currentData->data.number, number) == 0)
      return currentData->data;
    currentData = currentData->next;
  }

  Account emptyAccount;
  emptyAccount.code = -1;
  return emptyAccount;
}

AccountList *initializeAccountList()
{
  AccountList *list = (AccountList *)malloc(sizeof(AccountList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}

int validationCode(GenericType i, GenericType a)
{
  int code = *(int *)i;
  AccountList *list = (AccountList *)a;

  if (code == 0)
    return 0;
  if (list->head == NULL)
    return code == 0;
  AccountListItemPointer previousAccount = list->head;
  while (previousAccount->next != NULL)
  {
    if (code == previousAccount->data.code)
      return 1;
    previousAccount = previousAccount->next;
  }
  return code == previousAccount->data.code;
}

int validationAgency(GenericType i, GenericType a)
{
  char *agency = (char *)i;
  if (strlen(agency) != 6)
    return 1;

  for (int i = 0; i < 4; i++)
  {
    if (!isdigit(agency[i]))
      return 1;
  }

  if (agency[4] != '-')
    return 1;

  if (!isdigit(agency[5]))
    return 1;

  return 0;
}

int validationNumberType(GenericType i, GenericType a)
{
  char *number = (char *)i;

  if (number[0] == '0')
    return 0;

  if (strlen(number) != 8)
    return 1;

  for (int i = 0; i < 6; i++)
  {
    if (!isdigit(number[i]))
      return 1;
  }

  if (number[6] != '-')
    return 1;

  if (!isdigit(number[7]))
    return 1;

  return 0;
}

int validationNumber(GenericType i, GenericType a)
{
  char *number = (char *)i;

  if (number[0] == '0')
    return 1;

  int valid = validationNumberType(number, a);
  if (valid == 1)
    return 1;

  int position = findAccountPosition((AccountList *)a, number);
  if (position != -1)
    return 1;

  return 0;
}

int validationPassword(GenericType i, GenericType a)
{
  char *password = (char *)i;
  if (strlen(password) != 8)
    return 1;

  for (int i = 0; i < 8; i++)
  {
    if (!isdigit(password[i]))
      return 1;
  }

  return 0;
}

int validationType(GenericType i, GenericType a)
{
  char *type = (char *)i;
  char lowerType = tolower(*type);

  if (lowerType != 'c' && lowerType != 'p')
    return 1;
  return 0;
}

int validationStatus(GenericType i, GenericType a)
{
  char *status = (char *)i;

  for (int i = 0; i < (int)strlen(status); i++)
  {
    status[i] = tolower(status[i]);
  }

  if (strcmp(status, "ativo") != 0 && strcmp(status, "inativo") != 0)
    return 1;
  return 0;
}

int validationDay(GenericType i, GenericType a)
{
  int *day = (int *)i;
  if (*day < 1 || *day > 28)
    return 1;

  return 0;
}

/*
    Create an account
    @param list The list of accounts
    @param update If the account is being updated
    @param input If the account is being created
    @return The account created
*/
Account createAccount(AccountList *list, int update, int input)
{
  Account account;

  writeText("    CODIGO..:", 0, 6, 0);
  writeText("1 - BANCO...:", 0, 8, 0);
  writeText("2 - AGENCIA.:", 0, 10, 0);
  writeText("3 - NUMERO..:", 0, 12, 0);
  writeText("4 - TIPO....:", 0, 14, 0);
  writeText("5 - SALDO...:", 0, 16, 0);
  writeText("6 - LIMITE..:", 0, 18, 0);
  writeText("7 - STATUS..:", 0, 20, 0);
  writeText("8 - DIA RENDIMENTOS:", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1, 1);
  writeText("9 - SENHA..........:", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 1, 1);

  if (update == 0)
  {
    int *code = &account.code;

    getInput("%d", code, "Digite um numero valido e unico! Pressione 'Enter' para reescrever...", 17, 6, validationCode, list);

    if (account.code == 0)
    {
      return account;
    }
  }

  if (input == 1 || input == -1)
    getInput("%s", account.bank, "", 17, 8, noValid, NULL);
  if (input == 2 || input == -1)
    getInput("%s", account.agency, "Digite um formato valido (ex. 1234-5)! Pressione 'Enter' para reescrever...", 17, 10, validationAgency, NULL);
  if (input == 3 || input == -1)
    getInput("%s", account.number, "Ja usado ou invalido (ex. 123456-7)! Pressione 'Enter' para reescrever..", 17, 12, validationNumber, list);
  if (input == 4 || input == -1)
  {
    getInput("%c", &account.type, "C = Conta Corrente / P = Conta Poupanca! Pressione 'Enter' para reescrever..", 17, 14, validationType, NULL);
    account.type = tolower(account.type);
  }
  if (input == 5 || input == -1)
    getInput("%lf", &account.balance, "Digite um saldo valido! Pressione 'Enter' para reescrever...", 17, 16, noValid, NULL);
  if (((input == 6 || input == -1) && account.type == 'c') || (input == 6 && update == 1))
  {
    getInput("%lf", &account.limit, "Digite um limite valido! Pressione 'Enter' para reescrever...", 17, 18, noValid, NULL);
  }
  else if (account.type == 'p')
  {
    account.limit = 0;
    writeText("N/A", 17, 18, 1);
  }
  if (input == 7 || input == -1)
  {
    getInput("%s", account.status, "Digite apenas \"ativo\" e \"inativo\"! Pressione 'Enter' para reescrever...", 17, 20, validationStatus, NULL);
    for (int i = 0; i < (int)strlen(account.status); i++)
    {
      account.status[i] = tolower(account.status[i]);
    }
  }
  if (((input == 8 || input == -1) && account.type == 'p') || (input == 8 && update == 1))
  {
    getInput("%d", &account.interestDay, "Digite um dia entre 01 e 28! Pressione 'Enter' para reescrever...", SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1, validationDay, NULL);
  }
  else if (account.type == 'c')
  {
    account.interestDay = 0;
    writeText("N/A", SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1, 1);
  }
  if (input == 9 || input == -1)
    getInput("%s", account.password, "Senha deve ter 8 números! Pressione 'Enter' para reescrever...", SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 + 1, validationPassword, NULL);

  return account;
}

void printAccount(Account account)
{
  writeText("    CODIGO..:", 0, 6, 0);
  writeText("1 - BANCO...:", 0, 8, 0);
  writeText("2 - AGENCIA.:", 0, 10, 0);
  writeText("3 - NUMERO..:", 0, 12, 0);
  writeText("4 - TIPO....:", 0, 14, 0);
  writeText("5 - SALDO...:", 0, 16, 0);
  writeText("6 - LIMITE..:", 0, 18, 0);
  writeText("7 - STATUS..:", 0, 20, 0);
  writeText("8 - DIA RENDIMENTOS:", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1, 1);
  writeText("9 - SENHA..........:  ********", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 1, 1);

  goTo(17, 6);
  printf("%d", account.code);
  goTo(17, 8);
  puts(account.bank);
  goTo(17, 10);
  puts(account.agency);
  goTo(17, 12);
  puts(account.number);
  goTo(17, 14);
  if (account.type == 'c')
    puts("Conta Corrente");
  else
    puts("Conta Poupanca");
  goTo(17, 16);
  printf("%.2f", account.balance);
  goTo(17, 18);
  if (account.type == 'p')
    puts("N/A");
  else
    printf("%.2f", account.limit);
  goTo(17, 20);
  puts(account.status);
  goTo(SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1);
  if (account.type == 'c')
    puts("N/A");
  else
    printf("%d", account.interestDay);
}

/*
    Print an account in a specific position in the list
    @param list The list of accounts
    @param position The position of the account in the list
    @return The account in the position
*/
Account printAccountInPosition(AccountList *list, int position)
{
  AccountListItemPointer account = list->head;
  for (int i = 0; i < position; i++)
    account = account->next;

  printAccount(account->data);

  return account->data;
}
