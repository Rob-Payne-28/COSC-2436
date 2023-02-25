/*********************
Name: Robert Payne
Coding 05
Purpose: Assignment 05 - Stack program that is part of COSC-2436.
**********************/

#include "stack.h"

Stack::Stack(int customSize) {
    top = -1;
    size = customSize;
}

int Stack::getSize() {
    return size;
}

bool Stack::isEmpty() {
    return top < 0;
}

bool Stack::peek() {
    // ToDo: Make peek function
    return true;
}

bool Stack::pop() {
    // ToDo: Make pop function
    return true;
}

bool Stack::push() {
    // ToDo: Make push function
    return true;
}

