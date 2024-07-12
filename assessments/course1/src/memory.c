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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 * Refactor:
 * @author Alain Guimarães
 * @date: July 12 2024
 *
 */
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length) {
    if (src == dst || length == 0) {
        return dst;
    }

    uint8_t *ret = dst;

    if (src < dst) {
        // Copy from the end to the beginning to handle overlapping scenario
        // where source is before the destination
        src += length;
        dst += length;
        while (length--) {
            *--dst = *--src;
        }
    } else {
        // Copy from the beginning to the end for overlapping scenario
        // where source is after the destination
        while (length--) {
            *dst++ = *src++;
        }
    }

    return ret;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) { 
    #
    return my_memmove(src, dst, length);

} 

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    uint8_t *ptr = src;
    while (length--) {
        *ptr++ = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    uint8_t *start = src, *end = src + length - 1;
    while (start < end) {
        uint8_t temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    return src;
}
uint32_t * reserve_words(size_t length) { //Changed from int32_t to uint32_t
  return (uint32_t *)malloc(length * sizeof(uint32_t)); 
}

void free_words(uint32_t * src) {  //Changed from int32_t to uint32_t
  free(src);
}
