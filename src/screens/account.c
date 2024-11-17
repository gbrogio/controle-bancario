#include "../models/account.h"
#include "../functions/functions.h"
#include "../global.h"
#include "../models/transaction.h"
#include "screens.h"
#include <stdio.h>

char accountScreen(AccountList *accountList, TransactionList *transactionList,
                   AccountListItemPointer account) {
  char option;
  cls();
  writeText("SALDO ATUAL: R$", 0, 4, 0);
  printf("%.2f", account->data.balance);
  writeText("BEM VINDO DE VOLTA!", SCREEN_WIDTH, 4, 0);
  writeText("Entrou como: CLIENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("b - Voltar para a tela de login", SCREEN_WIDTH, SCREEN_HEIGHT - 3,
            0);

  writeText("1 - Registrar Entrada", 0, 6, 0);
  writeText("2 - Registar Saida", 0, 7, 0);
  writeText("3 - Transferir", 0, 8, 0);
  writeText("4 - Consultar Transacoes", 0, 9, 0);

  buildScreen();

  option = command();

  if (option == '1') {
    registerTransaction(transactionList, account, 'c');
    option = '0';
    return option;
  }

  if (option == '2') {
    registerTransaction(transactionList, account, 'd');
    option = '0';
    return option;
  }

  if (option == '3') {
    transfer(accountList, transactionList, account);
    option = '0';
    return option;
  }

  return option;
}