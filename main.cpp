/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char** argv) {

    std::cout << "Creating stack..." << std::endl;
    Stack s1;

    // Checks isEmpty method when stack is empty
    std::cout << "Testing isEmpty method when stack is empty" << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Is empty? " << std::boolalpha << s1.isEmpty() << std::endl;
    }

    // Testing pop in underflow conditions
    std::cout << "Testing pop method in underflow conditions, should return -1" << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Popping " << s1.pop() << std::endl;
    }

    // Testing peek in underflow conditions
    std::cout << "Testing peek method in underflow conditions, should return -1" << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Peeking " << s1.peek() << std::endl;
    }

    // Checks the push and peek methods until they start to enter overflow conditions
    std::cout << "Testing push and peek method under normal circumstances" << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << "Pushing. Successful? " << std::boolalpha << s1.push(i) << std::endl;
        std::cout << "Peeking "<< i <<", Value: " << s1.peek() << std::endl;
    }

    // Checks the push and peek method during overflow conditions
    // Checks whether the stack accepted the last push and verifies the last entered value
    std::cout << "Testing push and peek method under overflow conditions" << std::endl;
    for (int i = 0; i < 10; ++i) {
        if(s1.push(i)){
            std::cout << "Failed! Accepted an overflow condition! " << std::endl;
        } else {
            std::cout << "Successfully handled overflow condition." << std::endl;
            std::cout << "Verifying top is still 10: " << s1.peek() << std::endl;
        }
    }

    // Checks the isEmpty method when stack is not empty
    std::cout << "Testing isEmpty method when stack is empty. Should be false." << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Is empty? " << std::boolalpha << s1.isEmpty() << std::endl;
    }

    // Checks the pop and peek method during normal conditions
    // Verifies the last value on the stack
    std::cout << "Testing pop and peek method under normal conditions" << std::endl;
    for (int i = 10; i >= -1; --i) {;
        std::cout << "Peeking " << s1.peek() << std::endl;
        std::cout << "Popping " << s1.pop() << std::endl;
    }

    // Checks all methods work as intended in normal operations
    std::cout << "Testing all methods work under normal circumstances" << std::endl;
    for (int i = 0; i < 100; ++i) {
        std::cout << "isEmpty -> " << std::boolalpha << s1.isEmpty() << std::endl;
        std::cout << "Pushed "<< i <<" -> " << std::boolalpha << s1.push(i) << std::endl;
        std::cout << "Peeking "<< i <<" -> " << s1.peek() << std::endl;
        std::cout << "isEmpty -> " << std::boolalpha << s1.isEmpty() << std::endl;
        std::cout << "Popping "<< i <<" -> " << s1.pop() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}