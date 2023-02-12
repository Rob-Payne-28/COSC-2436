/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "stack.h"
#define STARTING_INDEX -1
#define DEFAULT_STACK_SIZE 10

Stack::Stack() {
    top = STARTING_INDEX;
    array = new int[DEFAULT_STACK_SIZE];
    size = DEFAULT_STACK_SIZE;
}

Stack::Stack(int customSize) {
    top = STARTING_INDEX;
    if(customSize >= 2){
        array = new int[customSize];
        size = customSize;
    } else {
        array = new int[DEFAULT_STACK_SIZE];
        size = DEFAULT_STACK_SIZE;
    }
}

Stack::~Stack(){
    delete[] array;
}

bool Stack::push(int newNum) {
    bool isSuccessful = (top < size-1);
    if (isSuccessful) {
        top = top + 1;
        array[top] = newNum;
    } else {
        throw std::runtime_error("OVERFLOW CONDITION!");
    }
    return isSuccessful;
}

int Stack::pop() {
    int value;
    if(isEmpty()){
        throw std::runtime_error("UNDERFLOW CONDITION, CANNOT POP!");
    } else {
        value = array[top];
        top = top - 1;
    }
    return value;
}

int Stack::peek() {
    int value;
    if(isEmpty()){
        throw std::runtime_error("UNDERFLOW CONDITION, CANNOT PEEK!");
    } else {
        value = array[top];
    }
    return value;
}

bool Stack::isEmpty() {
    return top == -1;
}

// For debugging!
void Stack::dumpstack() {
    for (int i = 0; i < top + 1; ++i) {
        std::cout << "Position " << i << " contains " << array[i] << std::endl;
    }
}