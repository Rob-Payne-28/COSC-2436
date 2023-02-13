/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

// Adds exception handling
#include <stdexcept>
#ifndef STACK_STACK_H
#define STACK_STACK_H

#define STARTING_INDEX -1
#define DEFAULT_STACK_SIZE 10

class Stack {

public:
    Stack();
    Stack(int);
    ~Stack();

    bool push(int);
    bool isEmpty();
    int pop();
    int peek();

protected:
    int top;
    int *array;
    int size;
};

#endif //STACK_STACK_H
