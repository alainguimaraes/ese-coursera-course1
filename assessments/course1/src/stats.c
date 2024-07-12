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
 * @file stats.c 
 * @brief This file contains functions to calculate and print various statistics
 * of a given array of unsigned char data.
 *
 * The functions include finding the minimum, maximum, mean, and median values 
 * of the array, as well as their corresponding indices. The file also includes 
 * a function to print the original array and a function to sort the array in
 * ascending order.
 *
 * @author Alain Guimarães
 * @date 07/01/2024
 *
 */

#include "stats.h"
#include <math.h>
/* Size of the Data Set */
#define SIZE (40)

unsigned int find_minimum_index(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        return 0;
    }
    unsigned int i;
    unsigned char min = *ptr;
    unsigned int min_index = 0;
    for (i = 1; i < size; i++) {
        if (*(ptr + i) < min) {
            min = *(ptr + i);
            min_index = i;
        }
    }
    return min_index;
}

unsigned int find_maximum_index(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        return 0;
    }
    unsigned int i;
    unsigned char max = *ptr;
    unsigned int max_index = 0;
    for (i = 1; i < size; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
            max_index = i;
        }
    }
    return max_index;
}

unsigned int find_median_index(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        return 0;
    }
    unsigned char temp;
    unsigned int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    return size / 2;
}

unsigned char find_median(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        return 0;
    }
    sort_array(ptr, size);
    
    // Calculate median without using round
    if (size % 2 == 0) { // even
        return (unsigned char)((*(ptr + (size / 2) - 1) + *(ptr + (size / 2))) / 2); 
    } else {            // odd
        return *(ptr + (size / 2)); 
    }
}

unsigned char find_mean(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        return 0;
    }

    unsigned int sum = 0;
    unsigned int i;
    for (i = 0; i < size; i++) {
        sum += *(ptr + i);
    }

    // Calculate mean without using round, handle rounding manually
    return (unsigned char)((sum + size / 2) / size); // Add size/2 for rounding
}

unsigned char find_maximum(unsigned char *ptr, unsigned int size)
{
    if (ptr == NULL || size == 0) {
        return 0;
    }
    unsigned int i;
    unsigned char max = *(ptr);
    for (i = 1; i < size; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int size)
{
    if (ptr == NULL || size == 0) {
        return 0;
    }

    unsigned int i;
    unsigned char min = *(ptr);
    for (i = 1; i < size; i++)
    {
        if (*(ptr + i) < min)
        {
            min = *(ptr + i);
        }
    }
    return min;
}

void sort_array(unsigned char *ptr, unsigned int size)
{
    if (ptr == NULL || size == 0) {
        return;
    }

    unsigned int i, j;
    unsigned char temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}
void print_statistics(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        PRINTF("Error: Invalid input dataset.\n"); // Use PRINTF
        return;
    }
    PRINTF("Minimum: %d (index: %d)\n", (int)find_minimum(ptr, size), find_minimum_index(ptr, size)); // Use PRINTF
    PRINTF("Maximum: %d (index: %d)\n", (int)find_maximum(ptr, size), find_maximum_index(ptr, size)); // Use PRINTF
    PRINTF("Mean: %d\n", (int)find_mean(ptr, size));   // Use PRINTF
    PRINTF("Median: %d (index: %d)\n", (int)find_median(ptr, size), find_median_index(ptr, size)); // Use PRINTF
}
void print_array(unsigned char *ptr, unsigned int size) {
    #ifdef VERBOSE  // Check if VERBOSE is defined
        unsigned int i;
        PRINTF("{");  // Use PRINTF macro
        for (i = 0; i < size; i++) {
            PRINTF("%d, ", *(ptr + i)); 
        }
        PRINTF("}\n"); 
    #endif  // No printing if VERBOSE is not defined
}
