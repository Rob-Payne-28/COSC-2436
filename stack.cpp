/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "stack.h"

#define MIN -1

Stack::Stack() {
    setTop(MIN);
}

Stack::Stack(int top) {
    setTop(top);
}

Stack::~Stack(){
}

void Stack::setTop(int top) {
    setTop(top);
}

bool Stack::push(int x) {
    bool isSuccessful = (top >= 10);
    if (isSuccessful) {
        a[++top] = x;
    }
    return isSuccessful;
}

int Stack::pop() {
    int value = -1;
    if(top > -1){
        value = a[top--];
    }
    return value;
}

bool Stack::isEmpty() {
    return top < 0;
}

int Stack::peek() {
    int value = -1;
    if(top > -1){
        value = a[top];
    }
    return value;
}