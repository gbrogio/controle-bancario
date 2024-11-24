#include "validations.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int validationDate(GenericType i, GenericType _) {
  UNUSED(_);
  char *date = (char *)i;
  int length = strlen(date);

  if (length != 10)
    return 1;

  // FORMAT VALIDATIONS dd
  if (!isdigit(date[0]) || !isdigit(date[1]))
    return 1;

  // FORMAT VALIDATIONS mm
  if (!isdigit(date[3]) || !isdigit(date[4]))
    return 1;

  // FORMAT VALIDATIONS yyyy
  if (!isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) ||
      !isdigit(date[9]))
    return 1;

  // FORMAT VALIDATIONS /
  if (date[2] != '/' || date[5] != '/')
    return 1;

  char dayString[3] = {date[0], date[1], '\0'};
  char monthString[3] = {date[3], date[4], '\0'};
  char yearString[5] = {date[6], date[7], date[8], date[9], '\0'};
  int day = atoi(dayString);
  int month = atoi(monthString);
  int year = atoi(yearString);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int todayYear = tm.tm_year + 1900;
  int todayMonth = tm.tm_mon + 1;
  int todayDay = tm.tm_mday;

  // BASIC VALIDATIONS
  if (day < 1 || day > 31)
    return 1;
  if (month < 1 || month > 12)
    return 1;

  // LEAP YEAR VALIDATIONS
  int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  if (month == 2 && isLeapYear && day > 29)
    return 1;
  if (month == 2 && !isLeapYear && day > 28)
    return 1;

  // MONTHS WITH 30 DAYS VALIDATIONS
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return 1;

  // FUTURE DATE VALIDATIONS
  if (year > todayYear)
    return 1;
  if (year == todayYear && month > todayMonth)
    return 1;
  if (year == todayYear && month == todayMonth && day > todayDay)
    return 1;

  return 0;
}