/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    // Generates a random seed
    srand(time(NULL));

    std::cout << "Creating stack..." << std::endl;
    Stack s1;

    // Checks isEmpty method when stack is empty
    std::cout << "Testing isEmpty method when stack is empty" << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Is empty? " << std::boolalpha << s1.isEmpty() << std::endl;
    }
    std::cout << std::endl;

    // Testing pop in underflow conditions
    std::cout << "Testing pop method in underflow conditions, should return -1" << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Popping " << s1.pop() << std::endl;
    }
    std::cout << std::endl;

    // Testing peek in underflow conditions
    std::cout << "Testing peek method in underflow conditions, should return -1" << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Peeking " << s1.peek() << std::endl;
    }
    std::cout << std::endl;

    // Checks the push and peek methods until they start to enter overflow conditions
    std::cout << "Testing push and peek method under normal circumstances" << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << "Pushing. Successful? " << std::boolalpha << s1.push(i) << std::endl;
        std::cout << "Peeking "<< i <<", Value: " << s1.peek() << std::endl;
    }
    std::cout << std::endl;

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
    std::cout << std::endl;

    // Checks the isEmpty method when stack is not empty
    std::cout << "Testing isEmpty method when stack is empty. Should be false." << std::endl;
    for (int i = 0; i < 11; ++i){
        std::cout << "Is empty? " << std::boolalpha << s1.isEmpty() << std::endl;
    }
    std::cout << std::endl;

    // Checks the pop and peek method during normal conditions
    // Verifies the last value on the stack
    std::cout << "Testing pop and peek method under normal conditions" << std::endl;
    for (int i = 10; i >= -1; --i) {;
        std::cout << "Peeking " << s1.peek() << std::endl;
        std::cout << "Popping " << s1.pop() << std::endl;
    }
    std::cout << std::endl;

    // Checks all methods work as intended in normal operations
    std::cout << "Testing all methods work under normal circumstances" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "isEmpty -> " << std::boolalpha << s1.isEmpty() << std::endl;
        std::cout << "Pushed "<< i <<" -> " << std::boolalpha << s1.push(i) << std::endl;
        std::cout << "Peeking "<< i <<" -> " << s1.peek() << std::endl;
        std::cout << "isEmpty -> " << std::boolalpha << s1.isEmpty() << std::endl;
        std::cout << "Popping "<< i <<" -> " << s1.pop() << std::endl;
        std::cout << std::endl;
    }

    // Runs 100 tests in random order
    std::cout << "Testing methods in a random order" << std::endl;
    for (int i = 0; i < 100; ++i) {
        //generates random number with 4 possible outcomes (0-3)
        int randomNum = rand() % 4;
        int pushNum;
        switch (randomNum) {
            case 0:
                if(s1.isEmpty()){
                    std::cout << "Stack is currently empty" << std::endl;
                } else {
                    std::cout << "Stack is not empty" << std::endl;
                }
                break;
            case 1:
                if(s1.isEmpty()){
                    std::cout << "Cannot pop! Stack currently empty!" << std::endl;
                } else {
                    std::cout << "Popping " << s1.pop() << "!" << std::endl;
                }
                break;
            case 2:
                pushNum = rand() % 10;
                if(s1.push(pushNum)){
                    std::cout << "Pushed " << s1.push(pushNum) << "!" << std::endl;
                } else {
                    std::cout << "Cannot push! Stack in overflow state!" << std::endl;
                }
                break;
            case 3:
                if(s1.peek() == -1){
                    std::cout << "Stack is currently empty" << std::endl;
                } else {
                    std::cout << "Top of stack is: " << s1.peek() << std::endl;
                }
                break;
        }

    }

    return 0;
}