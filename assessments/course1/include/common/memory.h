#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>   // For uint8_t, int32_t, uint32_t
#include <stddef.h>   // For size_t

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

// ... (other existing functions)

/**
 * @brief Moves a block of memory from one location to another.
 *
 * This function copies a block of `length` bytes from the source memory location (`src`) to the destination memory location (`dst`). It handles overlapping memory regions safely, ensuring data is not overwritten before it's copied.
 *
 * @param src Pointer to the source memory location.
 * @param dst Pointer to the destination memory location.
 * @param length Number of bytes to move.
 * @return Pointer to the destination memory location (`dst`).
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a block of memory from one location to another.
 *
 * This function copies a block of `length` bytes from the source memory location (`src`)
 * to the destination memory location (`dst`). The behavior is undefined if there is 
 * overlap of source and destination. Copy should still occur, but will likely corrupt your data.
 * All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param src Pointer to the source memory location.
 * @param dst Pointer to the destination memory location.
 * @param length Number of bytes to copy.
 * @return Pointer to the destination memory location (`dst`).
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a block of memory to a specified value.
 *
 * This function fills a block of `length` bytes starting at the memory location 
 * pointed to by `src` with the specified `value`.
 *
 * @param src Pointer to the starting address of the memory block.
 * @param length Number of bytes to set.
 * @param value The value to set each byte to.
 * @return Pointer to the source memory location (`src`).
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Zeros out a block of memory.
 *
 * This function sets all bytes within a block of `length` bytes starting at the 
 * memory location pointed to by `src` to zero (0x00).
 *
 * @param src Pointer to the starting address of the memory block.
 * @param length Number of bytes to zero out.
 * @return Pointer to the source memory location (`src`).
 */
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @brief Reverses the order of bytes in a memory block.
 *
 * This function reverses the order of `length` bytes starting at the memory 
 * location pointed to by `src`.
 *
 * @param src Pointer to the starting address of the memory block.
 * @param length Number of bytes to reverse.
 * @return Pointer to the source memory location (`src`).
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Dynamically allocates a block of memory for `length` words (32-bit integers).
 *
 * This function attempts to allocate a contiguous block of memory large enough to 
 * hold `length` number of 32-bit integers (words).
 *
 * @param length The number of words to allocate.
 * @return A pointer to the start of the allocated memory block if successful, 
 *         or a NULL pointer if the allocation fails.
 */
uint32_t * reserve_words(size_t length); //Changed from int32_t to uint32_t

/**
 * @brief Frees a block of memory previously allocated by `reserve_words`.
 *
 * This function releases a block of dynamically allocated memory that was 
 * previously obtained using the `reserve_words` function.
 *
 * @param src Pointer to the starting address of the memory block to be freed.
 */
void free_words(uint32_t * src); //Changed from int32_t to uint32_t

#endif /* __MEMORY_H__ */

