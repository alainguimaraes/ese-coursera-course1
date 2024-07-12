/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Alain Guimaraes
 * @date July 12 2024
 *
 */
#include <stdint.h>
#include <stdbool.h> 
#include "data.h"
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    uint8_t *start = ptr; // Store starting address of the buffer
    bool isNegative = false;

    // Handle 0 explicitly
    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0'; // Null-terminate the string
        return 1;    // Length of the string "0" is 1
    }

    // Handle negative numbers
    if (data < 0) {
        isNegative = true;
        data = -data;
    }

    // Convert digits to characters and store in reverse order
    while (data != 0) {
        uint8_t remainder = data % base;
        *ptr++ = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
        data /= base;
    }

    // Add negative sign if needed
    if (isNegative) {
        *ptr++ = '-';
    }

    // Add null terminator
    *ptr = '\0';

    // Reverse the string (in-place)
    uint8_t *end = ptr - 1; // Point to the last character before null terminator
    while (start < end) {
        uint8_t temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return ptr - start; // Return the length of the converted string
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    bool isNegative = (*ptr == '-');

    if (isNegative) {
        ptr++; // Skip the negative sign
    }

    // Calculate the maximum possible result for overflow detection
    int32_t max_value = INT32_MAX / base;
    int32_t max_digit = INT32_MAX % base;

    while (*ptr != '\0') { // Loop until null terminator
        uint8_t digitValue;
        if (*ptr >= '0' && *ptr <= '9') {
            digitValue = *ptr - '0';
        } else if (*ptr >= 'a' && *ptr <= 'f') {
            digitValue = *ptr - 'a' + 10;
        } else if (*ptr >= 'A' && *ptr <= 'F') {
            digitValue = *ptr - 'A' + 10;
        } else {
            return 0; // Invalid character encountered
        }

        // Check for overflow
        if (result > max_value || (result == max_value && digitValue > max_digit)) {
            return isNegative ? INT32_MIN : INT32_MAX;
        }

        result = result * base + digitValue;
        ptr++;
    }

    return isNegative ? -result : result;
}



