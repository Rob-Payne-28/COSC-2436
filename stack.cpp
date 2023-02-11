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

void Stack::push(int x) {
    if (top >= 10) {
        std::cout << "Stack Overflow \n" << std::endl;
    } else {
        a[++top] = x;
        std::cout << "Element Inserted \n" << std::endl;
    }
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

// function to check if stack is empty
void Stack::isEmpty() {
    if (top < 0) {
        std::cout << "Stack is empty \n" << std::endl;
    } else {
        std::cout << "Stack is not empty \n" << std::endl;
    }
}