#include <stdlib.h>
#include <string.h>
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
  strcpy(currentData->data.type, account.type);
  strcpy(currentData->data.status, account.status);
  currentData->data.balance = account.balance;
  currentData->data.limit = account.limit;
}

int findAccountPosition(AccountList *list, int code)
{
  if (list->head == NULL)
    return -1;

  AccountListItemPointer currentData = list->head;
  int position = 0;

  while (currentData != NULL)
  {
    if (currentData->data.code == code)
      return position;
    currentData = currentData->next;
    position++;
  }

  return -1;
}

Account getAccountByCode(AccountList *list, int code)
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
    if (currentData->data.code == code)
      return currentData->data;
    currentData = currentData->next;
  }

  Account emptyAccount;
  emptyAccount.code = -1;
  return emptyAccount;
}

AccountList initializeAccountList()
{
  AccountList list;
  list.head = NULL;
  list.tail = NULL;
  list.length = 0;
  return list;
}

int validationCode(int *code, AccountList *list)
{
    if (code == 0)
        return 0;
    if (list->head == NULL)
        return code == 0;
    AccountListItemPointer previousAccount = list->head;
    while (previousAccount->next != NULL)
    {
        if (*code == previousAccount->data.code)
            return 1;
        previousAccount = previousAccount->next;
    }
    return *code == previousAccount->data.code;
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

  writeText("    CODIGO..:", 0, 7, 0);
  writeText("1 - BANCO...:", 0, 9, 0);
  writeText("2 - AGENCIA.:", 0, 11, 0);
  writeText("3 - NUMERO..:", 0, 13, 0);
  writeText("4 - TIPO....:", 0, 15, 0);
  writeText("5 - SALDO...:", 0, 17, 0);
  writeText("6 - LIMITE..:", 0, 19, 0);
  writeText("7 - STATUS..:", 0, 21, 0);

  if (update == 0)
  {
    int *code = &account.code;

    getInput("%d", code,
             "Digite um numero valido e unico! Pressione 'Enter' para "
             "continuar...",
             27, 7, validationCode, list);

    if (account.code == 0)
    {
      return account;
    }
  }

  if (input == 1 || input == -1)
    getInput("%s", account.bank, "", 27, 9, noValid, NULL);
  if (input == 2 || input == -1)
    getInput("%s", account.agency, "", 27, 11, noValid, NULL);
  if (input == 3 || input == -1)
    getInput("%s", account.number, "", 27, 13, noValid, NULL);
  if (input == 4 || input == -1)
    getInput("%s", account.type, "", 27, 15, noValid, NULL);
  if (input == 5 || input == -1)
    getInput("%lf", &account.balance, "", 27, 17, noValid, NULL);
  if (input == 6 || input == -1)
    getInput("%lf", &account.limit, "", 27, 19, noValid, NULL);
  if (input == 7 || input == -1)
    getInput("%s", account.status, "", 27, 21, noValid, NULL);

  return account;
}

/*
    Print an account in a specific position in the list
    @param list The list of accounts
    @param position The position of the account in the list
    @return The account in the position
*/
void printAccount(AccountList *list, int position)
{
  AccountListItemPointer account = list->head;
  for (int i = 0; i < position; i++)
    account = account->next;

  writeText("    CODIGO..:", 0, 7, 0);
  writeText("1 - BANCO...:", 0, 9, 0);
  writeText("2 - AGENCIA.:", 0, 11, 0);
  writeText("3 - NUMERO..:", 0, 13, 0);
  writeText("4 - TIPO....:", 0, 15, 0);
  writeText("5 - SALDO...:", 0, 17, 0);
  writeText("6 - LIMITE..:", 0, 19, 0);
  writeText("7 - STATUS..:", 0, 21, 0);

  goTo(27, 7);
  printf("%d", account->data.code);
  goTo(27, 9);
  puts(account->data.bank);
  goTo(27, 11);
  puts(account->data.agency);
  goTo(27, 13);
  puts(account->data.number);
  goTo(27, 15);
  puts(account->data.type);
  goTo(27, 17);
  printf("%.2f", account->data.balance);
  goTo(27, 19);
  printf("%.2f", account->data.limit);
  goTo(27, 21);
  puts(account->data.status);
}
