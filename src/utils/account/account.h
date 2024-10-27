#ifndef ACCOUNT_H
#define ACCOUNT_H

/* Schema of accounts. Used on `AccountListItem` structure */
typedef struct
{
  int code;
  char bank[50];
  char agency[10];
  char number[20];
  char type[20];
  double balance;
  double limit;
  char status[10];
} Account;

typedef struct AccountListItem *AccountListItemPointer;

/*
  @param data Is the `Account` data.
  @param next Is a pointer for the next `Account` in list
*/
typedef struct AccountListItem
{
  Account data;
  AccountListItemPointer next;
} AccountListItem;

/*
  @param head A pointer for the first item in list
  @param tail A pointer for the last item in list
  @param length The length of the list
*/
typedef struct
{
  AccountListItemPointer head;
  AccountListItemPointer tail;
  int length;
} AccountList;

void pushAccount(AccountList *list, Account data);
void insertAccountIn(int position, AccountList *list, Account data);
void unshiftAccount(AccountList *list, Account data);
void shiftAccount(AccountList *list);
void popAccount(AccountList *list);
void alterAccountInPostion(AccountList *list, Account account, int position);
int findAccountPosition(AccountList *list, int code);
Account getAccountByCode(AccountList *list, int code);
AccountList initializeAccountList();

#endif