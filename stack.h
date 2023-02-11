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

    void setTop(int);
    bool push(int);
    bool isEmpty();
    int pop();

protected:
    int top;
    int a[10];
};

#endif //STACK_STACK_H
