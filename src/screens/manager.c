#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../global.h"
#include "../models/account.h"
#include "../functions/functions.h"
#include "screens.h"

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
    removeAccountByNumber(list);
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