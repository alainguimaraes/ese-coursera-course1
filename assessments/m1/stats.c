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



#include <stdio.h>
#include <math.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


void main() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

    // Print the original array
    printf("Original array: ");
    print_array(test, SIZE);

    // Calculate and print the statistics
    print_statistics(test, SIZE);
}


void print_statistics(unsigned char *ptr, unsigned int size) {
    if (ptr == NULL || size == 0) {
        printf("Error: Invalid input dataset.\n");
        return;
    }
    printf("Minimum: %d (index: %d)\n", (int)find_minimum(ptr, size), find_minimum_index(ptr, size));
    printf("Maximum: %d (index: %d)\n", (int)find_maximum(ptr, size), find_maximum_index(ptr, size));
    printf("Mean: %d\n", (int)find_mean(ptr, size));
    printf("Median: %d (index: %d)\n", (int)find_median(ptr, size), find_median_index(ptr, size));
}

void print_array(unsigned char *ptr, unsigned int size)
{
    unsigned int i;
    printf("{");
    for (i = 0; i < size; i++)
    {
        printf("%d, ", *(ptr + i));
    }
    printf("}\n");
}
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

unsigned char find_median(unsigned char *ptr, unsigned int size)
{
    if (ptr == NULL || size == 0) {
        return 0;
    }

    unsigned char temp;
    unsigned int i, j;
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
    return (unsigned char)round(*(ptr + size / 2));
}

unsigned char find_mean(unsigned char *ptr, unsigned int size)
{
    if (ptr == NULL || size == 0) {
        return 0;
    }

    unsigned int sum = 0;
    unsigned int i;
    for (i = 0; i < size; i++)
    {
        sum += *(ptr + i);
    }
    return (unsigned char)round((float)sum / size);
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
    return (unsigned char)round(max);
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
    return (unsigned char)round(min);
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

