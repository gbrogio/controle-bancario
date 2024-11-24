#include "../../../global.h"
#include "../../../models/account.h"
#include "../../functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AccountListItemPointer findMiddle(AccountListItemPointer head) {
  AccountListItemPointer slow = head;
  AccountListItemPointer fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

AccountListItemPointer mergeTwoLists(AccountListItemPointer l1,
                                     AccountListItemPointer l2) {
  AccountListItemPointer head =
      (AccountListItemPointer)malloc(sizeof(AccountListItem));
  AccountListItemPointer tail = head;

  while (l1 != NULL && l2 != NULL) {
    if (strcmp(l1->data.bank, l2->data.bank) < 0) {
      tail->next = l1;
      l1 = l1->next;
    } else {
      tail->next = l2;
      l2 = l2->next;
    }

    tail = tail->next;
  }

  tail->next = l1 != NULL ? l1 : l2;
  return head->next;
}

AccountListItemPointer sortList(AccountListItemPointer head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  AccountListItemPointer middle = findMiddle(head);
  AccountListItemPointer afterMiddle = middle->next;
  middle->next = NULL;

  AccountListItemPointer left = sortList(head);
  AccountListItemPointer right = sortList(afterMiddle);

  return mergeTwoLists(left, right);
}

void listAccountsAlphabetic(AccountList *list) {
  AccountListItemPointer account;

  // Copy list
  AccountListItemPointer current = list->head;
  AccountListItemPointer newHead = NULL;
  AccountListItemPointer newTail = NULL;

  while (current != NULL) {
    AccountListItemPointer newNode =
        (AccountListItemPointer)malloc(sizeof(AccountListItem));
    newNode->data = current->data;
    newNode->next = NULL;

    if (newHead == NULL) {
      newHead = newNode;
      newTail = newNode;
    } else {
      newTail->next = newNode;
      newTail = newNode;
    }

    current = current->next;
  }

  account = sortList(newHead);

  int page = 1;
  int noAccounts = 0;
  char continueListing;
  clearInputBuffer();

  do {
    cls();
    buildScreen();
    writeText("LISTAR CONTAS (ORDEM ALFABETICA)", SCREEN_WIDTH / 2, 4, 0);
    buildTableAccount(7);

    int printed = 0;
    for (int i = page * 0; i < 14; i++) {
      if (account == NULL) {
        noAccounts = 1;
        break;
      }

      printAccountTable(account->data, 8 + printed);
      printed++;

      account = account->next;
    }

    if (account == NULL && printed == 0) {
      changeForegroundColor(161, 161, 170);
      writeText("Nenhuma conta foi encontrada!", SCREEN_WIDTH / 2,
                SCREEN_HEIGHT / 2, 0);
      setDefaultColor();
    }

    writeText("b - VOLTAR", SCREEN_WIDTH, SCREEN_HEIGHT - 1, 0);
    writeText("Pressione 'Enter' para continuar: ", 0, SCREEN_HEIGHT - 1, 0);
    continueListing = awaitPressAnyKey(0);
    if (noAccounts)
      continueListing = 'b';
    else
      page++;
  } while (continueListing != 'b');
}