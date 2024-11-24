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
  writeText("SALDO ATUAL: ", 0, 4, 0);
  if (account->data.balance < 0)
    changeForegroundColor(220, 38, 38);
  else
    changeForegroundColor(22, 163, 74);
  printf("R$ %.2f", account->data.balance);
  setDefaultColor();
  writeText("BEM VINDO DE VOLTA!", SCREEN_WIDTH, 4, 0);
  writeText("Entrou como: CLIENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("b - Voltar para a tela de login", SCREEN_WIDTH, SCREEN_HEIGHT - 3,
            0);

  writeText("1 - Registrar Entrada", 0, 6, 0);
  writeText("2 - Registrar Saida", 0, 8, 0);

  if (account->data.type == 'p')
    changeForegroundColor(161, 161, 170);
  writeText("3 - Transferir", 0, 10, 0);
  writeText("4 - Transferir (COM DATA)", 0, 11, 0);
  if (account->data.type == 'p')
    setDefaultColor();
  writeText("5 - Registar Entrada (COM DATA)", 0, 7, 0);
  writeText("6 - Registar Saida (COM DATA)", 0, 9, 0);

  writeText("7 - Consultar Transacoes", 0, 12, 0);

  buildScreen();

  option = command();

  if (option == '1') {
    registerTransaction(transactionList, account, 'c', 0);
    option = '0';
    return option;
  }

  if (option == '2') {
    registerTransaction(transactionList, account, 'd', 0);
    option = '0';
    return option;
  }

  if (option == '3' && account->data.type != 'p') {
    transfer(accountList, transactionList, account, 0);
    option = '0';
    return option;
  } else if (option == '3' && account->data.type == 'p') {
    clearFooter();
    printMessage("Operacao nao permitida para contas poupanca!", 1);
    option = '0';
    return option;
  }

  if (option == '4' && account->data.type != 'p') {
    transfer(accountList, transactionList, account, 1);
    option = '0';
    return option;
  } else if (option == '4' && account->data.type == 'p') {
    clearFooter();
    printMessage("Operacao nao permitida para contas poupanca!", 1);
    option = '0';
    return option;
  }

  if (option == '5') {
    registerTransaction(transactionList, account, 'c', 1);
    option = '0';
    return option;
  }

  if (option == '6') {
    registerTransaction(transactionList, account, 'd', 1);
    option = '0';
    return option;
  }

  if (option == '7') {
    listTransactions(transactionList, account->data.number);
    option = '0';
    return option;
  }

  return option;
}