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
    a = new int[MAX];
}

Stack::Stack(int size) {
    setTop(MIN);
    if(size > MAX){
        a = new int[MAX];
    } else {
        a = new int[size];
    }
}

Stack::~Stack(){
    delete[] a;
}

void Stack::setTop(int customTop) {
    top = customTop;
}

bool Stack::push(int x) {
    bool isSuccessful = (top < 10);
    if (isSuccessful) {
        a[top] = x;
        top++;
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