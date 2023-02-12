/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

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

    void setTop(int);
    int getTop();
};

#endif //STACK_STACK_H
