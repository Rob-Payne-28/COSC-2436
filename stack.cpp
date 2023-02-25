/*********************
Name: Robert Payne
Coding 05
Purpose: Assignment 05 - Stack program that is part of COSC-2436.
**********************/

#include "stack.h"

Stack::Stack(int customSize){
    top = -1;
    size = customSize;
}

Stack::~Stack(){
    delete stack;
}

int Stack::getSize(){
    return size;
}

bool Stack::isEmpty(){
    return top < 0;
}

void Stack::peek(){
    // ToDo: Make peek function
}

bool Stack::pop(){
    // ToDo: Make pop function
    return true;
}

bool Stack::push(int newId, string& newInformation){
    bool success = false;

    if(top < size && newId > 0 && !newInformation.empty()){
        Data* data = new Data;
        data->id = newId;
        data->information = newInformation;
        stack[top++] = data;
        success = true;
    }

    return success;
}

