#include "../functions/functions.h"
#include "../global.h"
#include "../models/account.h"
#include "validations.h"
#include <ctype.h>
#include <string.h>

int validationCode(GenericType i, GenericType a) {
  int code = *(int *)i;
  AccountList *list = (AccountList *)a;

  if (code == 0)
    return 0;
  if (list->head == NULL)
    return code == 0;
  AccountListItemPointer previousAccount = list->head;
  while (previousAccount->next != NULL) {
    if (code == previousAccount->data.code)
      return 1;
    previousAccount = previousAccount->next;
  }
  return code == previousAccount->data.code;
}

int validationAgency(GenericType i, GenericType _) {
  UNUSED(_);

  char *agency = (char *)i;
  int agencyLenght = strlen(agency);

  if (agencyLenght < 3 || agencyLenght > 6)
    return 1;

  int validationDigitLength = 0;
  if (agency[agencyLenght - 2] == '-' && isdigit(agency[agencyLenght - 1])) {
    validationDigitLength = 2;
  }

  for (int i = 0; i < agencyLenght - validationDigitLength; i++) {
    if (!isdigit(agency[i]))
      return 1;
  }

  return 0;
}

int validationNumberType(GenericType i, GenericType _) {
  UNUSED(_);

  char *number = (char *)i;
  int numberLenght = strlen(number);

  if (number[0] == '0' && numberLenght == 1)
    return 0;

  // if number length minus verification digit is less than or bigger than the
  // minimum account number length so it is invalid
  if (numberLenght - 2 < 4 || numberLenght - 2 > 10)
    return 1;

  for (int i = 0; i < numberLenght - 2; i++) {
    if (!isdigit(number[i]))
      return 1;
  }

  if (number[numberLenght - 2] != '-')
    return 1;

  if (!isdigit(number[numberLenght - 1]))
    return 1;

  return 0;
}

int validationNumber(GenericType i, GenericType a) {
  char *number = (char *)i;

  if (number[0] == '0')
    return 1;

  int valid = validationNumberType(number, a);
  if (valid == 1)
    return 1;

  GetAccountBy accountFounded = getAccountByNumber((AccountList *)a, number, 0);
  if (accountFounded.position != -1)
    return 1;

  return 0;
}

int validationPassword(GenericType i, GenericType _) {
  UNUSED(_);

  char *password = (char *)i;
  if (strlen(password) != 8)
    return 1;

  for (int i = 0; i < 8; i++) {
    if (!isdigit(password[i]))
      return 1;
  }

  return 0;
}

int validationType(GenericType i, GenericType _) {
  UNUSED(_);

  char *type = (char *)i;
  char lowerType = tolower(*type);

  if (lowerType != 'c' && lowerType != 'p')
    return 1;
  return 0;
}

int validationStatus(GenericType i, GenericType _) {
  UNUSED(_);

  char *status = (char *)i;

  for (int i = 0; i < (int)strlen(status); i++) {
    status[i] = tolower(status[i]);
  }

  if (strcmp(status, "ativo") != 0 && strcmp(status, "inativo") != 0)
    return 1;
  return 0;
}

int validationDay(GenericType i, GenericType _) {
  UNUSED(_);

  int *day = (int *)i;
  if (*day < 1 || *day > 28)
    return 1;

  return 0;
}

int invalidPosition(GenericType i, GenericType a) {
  int position = *(int *)i;
  AccountList *list = (AccountList *)a;
  return position < 0 || position > list->length;
}