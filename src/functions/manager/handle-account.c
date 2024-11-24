#include "../../global.h"
#include "../../models/account.h"
#include "../../models/transaction.h"
#include "../../validations/validations.h"
#include "../functions.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

Account createAccount(AccountList *list, int update, int input) {
  Account account;

  if (update == 0) {
    account.yielded = 0;
  }

  writeText("    CODIGO..:", 0, 6, 0);
  writeText("1 - BANCO...:", 0, 8, 0);
  writeText("2 - AGENCIA.:", 0, 10, 0);
  writeText("3 - NUMERO..:", 0, 12, 0);
  writeText("4 - TIPO....:", 0, 14, 0);
  writeText("5 - STATUS..:", 0, 16, 0);
  writeText("6 - SALDO...:", 0, 18, 0);
  writeText("7 - LIMITE..:", 0, 20, 0);
  writeText("8 - DIA RENDIMENTOS:", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1, 1);
  writeText("9 - SENHA..........:", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 1, 1);

  if (update == 0) {
    int *code = &account.code;

    getInput(
        "%d", code, 0,
        "Digite um numero valido e unico! Pressione 'Enter' para reescrever...",
        17, 6, validationCode, list);

    if (account.code == 0) {
      return account;
    }
  }

  // UPDATE ACCOUNT BANK
  if (input == 1 || input == -1)
    getInput("%s", account.bank, 52, "", 17, 8, noValid, NULL);

  // UPDATE ACCOUNT AGENCY
  if (input == 2 || input == -1)
    getInput("%s", account.agency, 12,
             "Digite um formato valido (ex. 1234-5)! Pressione 'Enter' para "
             "reescrever...",
             17, 10, validationAgency, NULL);

  // UPDATE ACCOUNT NUMBER
  if (input == 3 || input == -1)
    getInput("%s", account.number, 16,
             "Ja usado ou invalido (ex. 123456-7)! Pressione 'Enter' para "
             "reescrever..",
             17, 12, validationNumber, list);

  // UPDATE ACCOUNT TYPE
  if (input == 4 || input == -1) {
    getInput("%c", &account.type, 0,
             "C = Conta Corrente / P = Conta Poupanca! Pressione 'Enter' para "
             "reescrever..",
             17, 14, validationType, NULL);
    account.type = tolower(account.type);
  }

  // UPDATE ACCOUNT STATUS
  if (input == 5 || input == -1) {
    getInput("%s", account.status, 10,
             "Digite apenas \"ativo\" e \"inativo\"! Pressione 'Enter' para "
             "reescrever...",
             17, 16, validationStatus, NULL);
    for (int i = 0; i < (int)strlen(account.status); i++) {
      account.status[i] = tolower(account.status[i]);
    }
  }

  // UPDATE ACCOUNT BALANCE
  if (input == 6 || input == -1) {
    if (account.status[0] == 'i') {
      account.balance = 0;
      writeText("N/A", 17, 18, 1);
    } else
      getInput("%lf", &account.balance, 0,
               "Digite um saldo valido! Pressione 'Enter' para reescrever...",
               17, 18, noValid, NULL);
  }

  // UPDATE ACCOUNT LIMIT
  if (((input == 7 || input == -1) && account.type == 'c') ||
      (input == 7 && update == 1)) {
    if (account.status[0] == 'i') {
      account.limit = 0;
      writeText("N/A", 17, 20, 1);
    } else
      getInput("%lf", &account.limit, 0,
               "Digite um limite valido! Pressione 'Enter' para reescrever...",
               17, 20, noValid, NULL);
  } else if (account.type == 'p') {
    account.limit = 0;
    writeText("N/A", 17, 20, 1);
  }

  // UPDATE ACCOUNT INTEREST DAY
  if (((input == 8 || input == -1) && account.type == 'p') ||
      (input == 8 && update == 1)) {
    getInput(
        "%d", &account.interestDay, 0,
        "Digite um dia entre 01 e 28! Pressione 'Enter' para reescrever...",
        SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1, validationDay, NULL);
  } else if (account.type == 'c') {
    account.interestDay = 0;
    writeText("N/A", SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 - 1, 1);
  }

  // UPDATE ACCOUNT PASSWORD
  if (input == 9 || input == -1)
    getInput("%s", account.password, 10,
             "Senha deve ter 8 numeros! Pressione 'Enter' para reescrever...",
             SCREEN_WIDTH / 2 + 22, SCREEN_HEIGHT / 2 + 1, validationPassword,
             NULL);

  return account;
}