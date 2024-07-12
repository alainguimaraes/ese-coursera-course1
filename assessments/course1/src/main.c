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
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alain Guimaraes
 * @date July 12 2024
 *
 */

#include "course1.h" // Include the course1.h header
#include "platform.h" 

int main(void) {
    #ifdef COURSE1  // Check if COURSE1 is defined at compile time
   	PRINTF("Running tests for course1 assessment!\n");
        course1();    // Call the course1() function
    #endif

    return 0;
}
