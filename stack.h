/*********************
Name: Robert Payne
Coding 05
Purpose: Assignment 05 - Stack program that is part of COSC-2436.
**********************/

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"

class Stack {

public:

    Stack();
    ~Stack();

    bool push();
    void peek();
    bool pop();
    bool isEmpty();

    int getSize();

private:

    int top;
    int size;
    Data **stack;

};

#endif //STACK_H
