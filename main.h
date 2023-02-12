/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#ifndef STACK_MAIN_H
#define STACK_MAIN_H

#include <iostream>
// Adds rand function
#include <cstdlib>
// Adds time function used for random seed generation
#include <ctime>
// Adds exception handling
#include <stdexcept>
// Adds constants for INT_MAX and INT_MIN for random number generation
#include <climits>
#include "stack.h"

// Defines how large you want the stack to be. Adjust to test other sizes.
#define SIZE 100
// Defines how many times you want the tests to run in certain states (underflow/overflow).
#define TEST_RUNS 10000
// Defines the range of numbers possible for our random integers, from INT_MIN to INT_MAX + 1.
#define RANGE 4294967296

#endif //STACK_MAIN_H
