/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "stack.h"
#define MIN -1
#define MAX 10

Stack::Stack() {
    setTop(MIN);
    array = new int[MAX];
}

Stack::Stack(int size) {
    setTop(MIN);
    if(size > MAX){
        array = new int[MAX];
    } else {
        array = new int[size];
    }
}

Stack::~Stack(){
    delete[] array;
}

void Stack::setTop(int newTop) {
    top = newTop;
}

bool Stack::push(int newNum) {
    bool isSuccessful = (top < 10);
    if (isSuccessful) {
        array[++top] = newNum;
        setTop(top++);
    }
    return isSuccessful;
}

int Stack::pop() {
    int value = -1;
    if(top > -1){
        value = array[top];
        setTop(--top);
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