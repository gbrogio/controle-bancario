



#include "../global.h"
#include "../models/account.h"
#include "../models/transaction.h"
#include "../functions/functions.h"
#include "screens.h"

char accountScreen(AccountList *accountList, TransactionList *transactionList, AccountListItemPointer client)
{
  char option;
  cls();
  writeText("BEM VINDO DE VOLTA!", SCREEN_WIDTH, 4, 0);
  writeText("Entrou como: CLIENTE", 0, SCREEN_HEIGHT - 3, 0);
  writeText("b - Voltar para a tela de login", SCREEN_WIDTH, SCREEN_HEIGHT - 3, 0);

  writeText("1 - Registrar Entrada", 0, 6, 0);
  writeText("2 - Registar Saida", 0, 7, 0);
  writeText("3 - Consultar Transacoes", 0, 8, 0);

  buildScreen();

  option = command();

  if (option == '1')
  {
    createTransaction(transactionList, client, 'c');
    option = '0';
    return option;
  }

  return option;
}