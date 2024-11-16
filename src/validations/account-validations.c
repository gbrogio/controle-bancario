#include <ctype.h>
#include <string.h>
#include "validations.h"
#include "../models/account.h"
#include "../functions/functions.h"
#include "../global.h"

int validationCode(GenericType i, GenericType a)
{
  int code = *(int *)i;
  AccountList *list = (AccountList *)a;

  if (code == 0)
    return 0;
  if (list->head == NULL)
    return code == 0;
  AccountListItemPointer previousAccount = list->head;
  while (previousAccount->next != NULL)
  {
    if (code == previousAccount->data.code)
      return 1;
    previousAccount = previousAccount->next;
  }
  return code == previousAccount->data.code;
}

int validationAgency(GenericType i, GenericType a)
{
  char *agency = (char *)i;
  if (strlen(agency) != 6)
    return 1;

  for (int i = 0; i < 4; i++)
  {
    if (!isdigit(agency[i]))
      return 1;
  }

  if (agency[4] != '-')
    return 1;

  if (!isdigit(agency[5]))
    return 1;

  return 0;
}

int validationNumberType(GenericType i, GenericType a)
{
  char *number = (char *)i;

  if (number[0] == '0')
    return 0;

  if (strlen(number) != 8)
    return 1;

  for (int i = 0; i < 6; i++)
  {
    if (!isdigit(number[i]))
      return 1;
  }

  if (number[6] != '-')
    return 1;

  if (!isdigit(number[7]))
    return 1;

  return 0;
}

int validationNumber(GenericType i, GenericType a)
{
  char *number = (char *)i;

  if (number[0] == '0')
    return 1;

  int valid = validationNumberType(number, a);
  if (valid == 1)
    return 1;

  int position = findAccountPosition((AccountList *)a, number);
  if (position != -1)
    return 1;

  return 0;
}

int validationPassword(GenericType i, GenericType a)
{
  char *password = (char *)i;
  if (strlen(password) != 8)
    return 1;

  for (int i = 0; i < 8; i++)
  {
    if (!isdigit(password[i]))
      return 1;
  }

  return 0;
}

int validationType(GenericType i, GenericType a)
{
  char *type = (char *)i;
  char lowerType = tolower(*type);

  if (lowerType != 'c' && lowerType != 'p')
    return 1;
  return 0;
}

int validationStatus(GenericType i, GenericType a)
{
  char *status = (char *)i;

  for (int i = 0; i < (int)strlen(status); i++)
  {
    status[i] = tolower(status[i]);
  }

  if (strcmp(status, "ativo") != 0 && strcmp(status, "inativo") != 0)
    return 1;
  return 0;
}

int validationDay(GenericType i, GenericType a)
{
  int *day = (int *)i;
  if (*day < 1 || *day > 28)
    return 1;

  return 0;
}

int invalidPosition(GenericType i, GenericType a)
{
  int position = *(int *)i;
  AccountList *list = (AccountList *)a;
  return position < 0 || position > list->length;
}