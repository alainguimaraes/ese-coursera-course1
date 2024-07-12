/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * ... (rest of the copyright notice)
 ******************************************************************************/
/**
 * @file data.h
 * @brief Declarations for integer/string conversion functions
 *
 * This header file provides function prototypes for converting between integer
 * and ASCII string representations.
 *
 * @author Alain Guimaraes
 * @date July 12, 2024
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>   // For uint8_t, int32_t, uint32_t

/**
 * @brief Converts a signed 32-bit integer to an ASCII string.
 *
 * This function converts the given `data` (a signed 32-bit integer) into a null-terminated ASCII string representation based on the specified `base` (2-16).  The resulting string is stored in the buffer pointed to by `ptr`. 
 * 
 * Note: This function handles negative numbers and ensures the string is null-terminated.
 *
 * @param data The signed 32-bit integer to convert.
 * @param ptr Pointer to the buffer where the resulting string will be stored.
 * @param base The base (2-16) for the conversion.
 * @return The length of the converted string (including the negative sign, if applicable).
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
/**
 * @brief Converts an ASCII string to a signed 32-bit integer.
 *
 * This function converts the null-terminated ASCII string `ptr` into a signed 32-bit integer based on the specified `base` (2-16).
 *
 * @param ptr Pointer to the null-terminated ASCII string to convert.
 * @param digits The number of digits in the string.
 * @param base The base (2-16) of the string.
 * @return The converted signed 32-bit integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */

