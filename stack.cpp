/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "stack.h"
#include<iostream>

#define MIN -1

Stack::Stack() {
    setTop(-1);
}

Stack::Stack(int customTop) {
    setTop(customTop);
}

Stack::~Stack(){
}

void Stack::setTop(int customTop) {
    top = customTop;
}

bool Stack::push(int x) {
    bool isSuccessful = (top >= 10);

    if (isSuccessful) {
        a[++top] = x;
    }

    return isSuccessful;
}

// function to remove data from the top of the stack
int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow \n" << std::endl;
        return 0;
    } else {
        int d = a[top--];
        return d;
    }
}

bool Stack::isEmpty() {
    return top < 0;
}