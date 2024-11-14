#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./transaction.h"
#include "../account/account.h"
#include "../../global/global.h"

void pushTransaction(TransactionList *list, Transaction data)
{
  TransactionListItemPointer newData = (TransactionListItemPointer)malloc(sizeof(TransactionListItem));

  newData->data = data;
  newData->next = NULL;
  newData->prev = list->tail;

  if (list->head == NULL)
    list->head = newData;
  else
    list->tail->next = newData;

  list->tail = newData;
  list->length++;
}

/* 
void shiftTransaction(TransactionList *list)
{
  if (list->head == NULL)
    return;

  TransactionListItemPointer lastData = list->tail;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  free(lastData);
  list->length--;  
} */

TransactionList *initializeTransactionList()
{
  TransactionList *list = (TransactionList *)malloc(sizeof(TransactionList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}

/*
    Create an account
    @param list The list of accounts
    @param update If the account is being updated
    @param input If the account is being created
    @return The account created
*/
Transaction createTransaction(TransactionList *list, AccountListItem *account, char type)
{
  Transaction transaction;
  transaction.id = list->length + 1;

  writeText("VALOR TRANSACAO..:", 0, SCREEN_HEIGHT / 2, 4);
  getInput("%lf", &transaction.value, "Digite um valor valido! Pressione 'Enter' para reescrever...", 22, SCREEN_HEIGHT / 2, noValid, NULL);

  transaction.type = type;
  strcpy(transaction.accountNumber, account->data.number);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int ano = tm.tm_year + 1900;
  sprintf(transaction.movimentDate, "%02d/%02d/%04d as %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, ano, tm.tm_hour, tm.tm_min, tm.tm_sec);

  if (type == 'd')
    account->data.balance -= transaction.value;
  else
    account->data.balance += transaction.value;

  transaction.balance = account->data.balance;

  return transaction;
}

void printTransaction(Transaction transaction)
{
  writeText("IDENTIFICADOR....:", 0, 6, 0);
  writeText("NUMERO DA CONTA..:", 0, 8, 1);
  writeText("DATA TRANSACAO...:", 0, 10, 2);
  writeText("TIPO TRANSACAO...:", 0, 12, 3);
  writeText("VALOR TRANSACAO..:", 0, 14, 4);
  writeText("SALDO NA CONTA...:", 0, 16, 4);

  goTo(22, 6);
  printf("%d", transaction.id);
  goTo(22, 8);
  printf("%s", transaction.accountNumber);
  goTo(22, 10);
  puts(transaction.movimentDate);
  goTo(22, 12);
  if (transaction.type == 'c')
    puts("Credito");
  else
    puts("Debito");
  goTo(22, 14);
  printf("%.2f", transaction.value);
  goTo(22, 16);
  printf("%.2f", transaction.balance);
}

/*
    Print an transaction in a specific position in the list
    @param list The list of transactions
    @param position The position of the transaction in the list
    @return The transaction in the position
*/
Transaction printTransactionInPosition(TransactionList *list, int position)
{
  TransactionListItemPointer transaction = list->head;
  for (int i = 0; i < position; i++)
    transaction = transaction->next;

  printTransaction(transaction->data);

  return transaction->data;
}
