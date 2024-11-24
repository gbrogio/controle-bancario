#

## Linux

If you are using Linux execute the command before build the project:

```bash
chmod +x start-linux
```

## Rules for getting Accounts

- [x] General consult
- [x] Account number consult
- [x] Alphabetic consult
- [x] Inative accounts consult
- [x] Only credit accounts

## Rules for Transactions

To determine if a year is a leap year, there is a basic rule: leap years are those that are multiples of 4, that is, every four years we have a leap year. On the other hand, these years are not multiples of 100 (for example, 1800, 1900, 2100), except for multiples of 400 (for example, 1600, 2000, 2400).

- [x] Data Transactions
  - [x] When receiving the date dd/mm/yyyy, validate to check if it is a valid date.
  - [x] Invert to yyyymmdd and pass it to an atoi.
  - [x] Get the last transaction of the account.
  - [x] If the date of the most recent transaction is greater than the date of the current transaction, then return an error; otherwise, allow the transaction to occur.

## Extra Rules for Savings Accounts

- [x] Implement monthly yield rule for savings accounts.
- [x] Add account anniversary day field.
- [x] Calculate yield based on the anniversary date.
- [x] Update account balance with the monthly yield.
- [x] Create a transaction for the user about the credited yield.
