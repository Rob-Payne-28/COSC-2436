/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "stack.h"
#define MIN -1
#define MAX 10

Stack::Stack() {
    top = MIN;
    array = new int[MAX];
}

Stack::Stack(int size) {
    top = MIN;
    if(size > MAX){
        array = new int[MAX];
        size = MAX-1;
    } else {
        array = new int[size];
        size = size-1;
    }
}

Stack::~Stack(){
    delete[] array;
}

bool Stack::push(int newNum) {
    bool isSuccessful = (top < size);
    if (isSuccessful) {
        array[top + 1] = newNum;
        top = top + 1;
    }
    return isSuccessful;
}

int Stack::pop() {
    int value = -1;
    if(top > -1){
        value = array[top];
        top = top - 1;
    }
    return value;
}

bool Stack::isEmpty() {
    return top < 0;
}

int Stack::peek() {
    int value = -1;
    if(top > -1){
        value = array[top];
    }
    return value;
}