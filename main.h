/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#ifndef STACK_MAIN_H
#define STACK_MAIN_H

#include <iostream>
// Adds random number generation using arc4random(). I had trouble with rand() so I opened the docs
// and it said it was deprecated.
#include <stdlib.h>
// Adds exception handling
#include <stdexcept>
#include "stack.h"

// Defines how large you want the stack to be. Adjust to test other sizes.
#define SIZE 100
// Defines how many times you want the tests to run in certain states (underflow/overflow).
#define TEST_RUNS 10000

#endif //STACK_MAIN_H
