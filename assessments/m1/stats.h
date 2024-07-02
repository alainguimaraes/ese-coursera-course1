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
 * @file stats.h 
 * @brief Statistics functions prototype and documentation
 *
 * This file contains the prototypes for perfoming analystics on a dataset
 *
 *
 * @author Alain Guimarães
 * @date 07/01/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes a pointer to an array of integers and its size as input and prints
 * the minimum, maximum, mean, and median values of the array to the console.
 *
 * @param data The array of integers
 * @param length The length of the array
 */
void print_statistics(unsigned char *ptr, unsigned int size);

/**
 * @brief Print the array of data to the console
 *
 * This function takes a pointer to an array of integers and its size as input and prints
 * each element of the array to the console, separated by a space.
 *
 * @param data The array of integers
 * @param length The length of the array
 */
void print_array(unsigned char *ptr, unsigned int size);

/**
 * @brief Calculates the median of an array of integers
 *
 * This function takes a pointer to an array of integers and its size as input and calculates
 * the median value of the array. The array is sorted in ascending order before calculating
 * the median.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The median value of the array
 */
unsigned char find_median(unsigned char *ptr, unsigned int size);


/**
 * @brief Calculate the mean of an array of integers
 *
 * This function takes a pointer to an array of integers and its size as input and calculates
 * the mean value of the array.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The mean value of the array
 */
unsigned char find_mean(unsigned char *ptr, unsigned int size);
/**
 * @brief Find the maximum value in an array of integers
 *
 * This function takes a pointer to an array of integers and its size as input and finds
 * the maximum value in the array.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The maximum value in the array
 */
unsigned char find_maximum(unsigned char *ptr, unsigned int size);
/**
 * @brief Find the minimum value in an array of integers
 *
 * This function takes a pointer to an array of integers and its size as input and finds
 * the minimum value in the array.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The minimum value in the array
 */
unsigned char find_minimum(unsigned char *ptr, unsigned int size);
/**
 * @brief Sorts the array from largest to smallest
 *
 * This function takes a pointer to an array of integers and its size as input and sorts
 * the array in descending order using a bubble sort algorithm.
 *
 * @param data The array of integers
 * @param length The length of the array
 */
void sort_array(unsigned char *ptr, unsigned int size);
/**
 * @brief Finds the index of the minimum value in the input array
 *
 * This function takes a pointer to an array of integers and its size as input and finds
 * the index of the minimum value in the array.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The index of the minimum value in the array
 */
 unsigned int find_minimum_index(unsigned char *ptr, unsigned int size);
/**
 * @brief Finds the index of the maximum value in the input array
 *
 * This function takes a pointer to an array of integers and its size as input and finds
 * the index of the maximum value in the array.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The index of the maximum value in the array
 */
unsigned int find_maximum_index(unsigned char *ptr, unsigned int size);
/**
 * @brief Finds the index of the median value in the input array
 *
 * This function takes a pointer to an array of integers and its size as input and finds
 * the index of the median value in the array.
 *
 * @param data The array of integers
 * @param length The length of the array
 * @return The index of the median value in the array
 */
unsigned int find_median_index(unsigned char *ptr, unsigned int size);

#endif /* __STATS_H__ */
