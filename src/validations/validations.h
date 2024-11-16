#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include "../global.h"

/**
 * @brief Validates code data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationCode(GenericType i, GenericType a);

/**
 * @brief Validates agency data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationAgency(GenericType i, GenericType a);

/**
 * @brief Validates account number format data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationNumberType(GenericType i, GenericType a);

/**
 * @brief Validates account number data. Validate if account exists.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationNumber(GenericType i, GenericType a);

/**
 * @brief Validates password data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationPassword(GenericType i, GenericType a);

/**
 * @brief Validates account type data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationType(GenericType i, GenericType a);

/**
 * @brief Validates account status data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationStatus(GenericType i, GenericType a);

/**
 * @brief Validates account interest day data.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int validationDay(GenericType i, GenericType a);

/**
 * @brief Validates if the position is valid.
 * 
 * @param i Input data.
 * @param a Additional data.
 * @return int 1 if the data is invalid, 0 if it is valid.
 */
int invalidPosition(GenericType i, GenericType a);

/**
 * @brief Always accept the data.
 */
int noValid();

#endif