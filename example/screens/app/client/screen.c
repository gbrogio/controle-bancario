#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../global/global.h"
#include "../../../utils/screen/screen.h"
#include "./screen.h"
#include "../../../utils/account/account.h"
#include "../../../utils/transaction/transaction.h"

char clientScreen(TransactionList *list, AccountListItem *client)
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
    createTransaction(list, client, 'c');
    option = '0';
    return option;
  }

  return option;
}
