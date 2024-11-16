#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./functions.h"
#include "../models/account.h"
#include "../global.h"

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


void insertAccountIn(int position, AccountList *list, Account data)
{
  if (list->head == NULL || position < 0 || position > list->length)
    return;

  AccountListItemPointer newData = (AccountListItemPointer)malloc(sizeof(AccountListItem));
  newData->data = data;

  AccountListItemPointer currentData = list->head;
  AccountListItemPointer previousData = NULL;

  for (int i = 0; i < position; i++)
  {
    previousData = currentData;
    currentData = currentData->next;
  }

  if (previousData == NULL)
  {
    newData->next = list->head;
    list->head = newData;
  }
  else
  {
    previousData->next = newData;
    newData->next = currentData;
  }

  list->length++;
}

void unshiftAccount(AccountList *list, Account data)
{
  AccountListItemPointer newData = (AccountListItemPointer)malloc(sizeof(AccountListItem));

  newData->data = data;
  newData->next = list->head;
  list->head = newData;
  if (list->tail == NULL)
    list->tail = newData;
  list->length++;
}

void shiftAccount(AccountList *list)
{
  if (list->head == NULL)
    return;

  AccountListItemPointer firstData = list->head;
  list->head = list->head->next;
  free(firstData);
  list->length--;

  if (list->head == NULL)
    list->tail = NULL;
}

void popAccount(AccountList *list)
{
  if (list->head == NULL)
    return;

  AccountListItemPointer lastData = list->tail;
  AccountListItemPointer currentData = list->head;

  if (currentData == lastData)
  {
    free(lastData);
    list->head = NULL;
    list->tail = NULL;
  }
  else
  {
    while (currentData->next != lastData)
    {
      currentData = currentData->next;
    }
    currentData->next = NULL;
    list->tail = currentData;
    free(lastData);
  }
  list->length--;
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

AccountListItemPointer getAccountByNumber(AccountList *list, char number[])
{
  if (list->head == NULL)
  {
    Account emptyAccount;
    emptyAccount.code = -1;
    return NULL;
  }

  AccountListItemPointer currentData = list->head;

  while (currentData != NULL)
  {
    if (strcmp(currentData->data.number, number) == 0)
      return currentData;
    currentData = currentData->next;
  }

  Account emptyAccount;
  emptyAccount.code = -1;
  return NULL;
}

AccountList *initializeAccountList()
{
  AccountList *list = (AccountList *)malloc(sizeof(AccountList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
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

Account printAccountInPosition(AccountList *list, int position)
{
  AccountListItemPointer account = list->head;
  for (int i = 0; i < position; i++)
    account = account->next;

  printAccount(account->data);

  return account->data;
}