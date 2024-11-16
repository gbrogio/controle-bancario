#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H

/* Schema of accounts. Used on `AccountListItem` structure */
typedef struct
{
  int code;
  char bank[50];
  char agency[7];
  char number[9];
  char type;
  double balance;
  double limit;
  char status[10];
  char password[9];
  int interestDay;
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

#endif