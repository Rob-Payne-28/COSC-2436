/*********************
Name: Robert Payne
Coding 05
Purpose: Assignment 05 - Stack program that is part of COSC-2436.
**********************/

#include "stack.h"

Stack::Stack(int customSize){
    top = EMPTY;
    // evaluates if the passed in value is >= 2, if not, just use the default size.
    size = (customSize >= 2) ? customSize : DEFAULT_SIZE;
    stack = new Data*[size];
}

Stack::~Stack(){
    // deletes all values within the stack, then deletes the stack
    for (int i = 0; i <= top; ++i) {
        delete stack[i];
    }
    delete [] stack;
}

int Stack::getSize(){
    return size;
}

bool Stack::isEmpty(){
    return top < 0;
}

bool Stack::peek(Data& returnData){
    bool success = false;

    if(isEmpty()){
        returnData.id = EMPTY;
        returnData.information = EMPTY_STRING;
    } else {
        returnData = *stack[top];
        success = true;
    }

    return success;
}

bool Stack::pop(Data& returnData){
    bool success = false;

    if(isEmpty()){
        returnData.id = EMPTY;
        returnData.information = EMPTY_STRING;
    } else {
        returnData = *stack[top];
        delete stack[top];
        top -= 1;
        success = true;
    }

    return success;
}

bool Stack::push(int newId, string& newInformation){
    bool success = false;

    if(top < size - 1){
        Data* data = new Data;
        data->id = newId;
        data->information = newInformation;
        top += 1;
        stack[top] = data;
        success = true;
    }

    return success;
}
