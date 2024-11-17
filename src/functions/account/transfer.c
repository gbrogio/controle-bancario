#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../global.h"
#include "../functions.h"
#include "../../models/account.h"
#include "../../validations/validations.h"

void transfer(AccountList *accountList, TransactionList *transactionList, AccountListItem *account)
{
  if (accountList->length <= 1)
  {
    printMessage("Nao ha outras contas cadastradas.");
    return;
  }

  char doAgain = 's';
  do
  {
    cls();
    buildScreen();
    writeText("TRANSFERIR PARA", SCREEN_WIDTH / 2, 4, 0);

    writeText("Numero da conta..:", SCREEN_WIDTH / 2 - 14,
              SCREEN_HEIGHT / 2, 0);

    char number[8];

    getInput("%s", number,
             "Digite um numero valido! Pressione 'Enter' para continuar...",
             SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, validationNumberType, accountList);

    if (number[0] == '0') {
      clearFooter();
      doAgain = confirm("Deseja transferir para outra conta?");
      continue;
    }

    GetAccountByNumber accountFounded = getAccountByNumber(accountList, number);

    if (accountFounded.account == NULL || accountFounded.account->data.number == account->data.number)
    {
      printMessage("Conta nao encontrada! Pressione 'Enter' para continuar...");
      continue;
    }

    cls();
    buildScreen();
    writeText("TRANSFERIR PARA", SCREEN_WIDTH / 2, 4, 0);
    printAccount(accountFounded.account->data);
    clearFooter();
    char confirmation = confirm("Deseja transferir para essa conta?");
    if (confirmation == 's')
    {
      if (accountList->head == NULL)
        return;

      Transaction transaction = createTransaction(transactionList, account, accountFounded.account, 'd');
      pushTransaction(transactionList, transaction);
    }

    clearFooter();
    doAgain = confirm("Deseja transferir para outra conta?");
  } while (doAgain == 's');
}
    

