/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "main.h"
#define SIZE 1
#define TEST_RUNS 10

int main(int argc, char** argv) {
    // Generates a random seed for random testing
    srand(time(NULL));

    // Create stack
    std::cout << "Creating stack with size of " << SIZE << "..." << std::endl;
    Stack stack(SIZE);

    int stackSize;
    if(SIZE >= 2){
        stackSize = SIZE;
    } else {
        std::cout << " Stack below minimum size. Falling back to default stack size of 10." << std::endl;
        stackSize = 10;
    }
    std::cout << std::endl;

    // Test is empty function when empty
    std::cout << "Testing that stack is empty" << std::endl;
    if(stack.isEmpty()){
        std::cout << " Stack is empty" << std::endl;
    } else {
        std::cout << " Stack is not empty" << std::endl;
    }
    std::cout << std::endl;

    // Fills stack
    std::cout << "Filling stack" << std::endl;
    for (int i = 0; i < stackSize; ++i) {
        try {
            stack.push(i);
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
        std::cout << " Peeking: " << stack.peek() << std::endl;
    }
    std::cout << std::endl;

    // Test is empty function when stack isn't empty
    std::cout << "Testing that stack is not empty" << std::endl;
    if(stack.isEmpty()){
        std::cout << " Stack is empty" << std::endl;
    } else {
        std::cout << " Stack is not empty" << std::endl;
    }
    std::cout << std::endl;

    // Test push in overflow condition
    std::cout << "Testing push in overflow conditions" << std::endl;
    for (int i = 0; i < TEST_RUNS; ++i) {
        try {
            stack.push(i);
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Empties Stack
    std::cout << "Emptying stack" << std::endl;
    for (int i = stackSize; i > 0; --i) {
        try {
            std::cout << " Peeking: " << stack.peek() << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
        try {
            std::cout << " Popping: " << stack.pop() << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Tests pop in underflow
    std::cout << "Testing pop in underflow" << std::endl;
    for (int i = 0; i < TEST_RUNS; ++i) {
        try {
            std::cout << " Popping: " << stack.pop() << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Tests peek in underflow
    std::cout << "Testing peek in underflow" << std::endl;
    for (int i = 0; i < TEST_RUNS; ++i) {
        try {
            std::cout << " Peeking: " << stack.peek() << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
    }
    std::cout << std::endl;

//    // Runs tests in random order
//    std::cout << "Testing methods in a random order" << std::endl;
//    for (int i = 0; i < TEST_RUNS; ++i) {
//        //generates random number with 4 possible outcomes (0-3)
//        int randomNum = rand() % 4;
//        int pushNum;
//        switch (randomNum) {
//            case 0:
//                if(stack.isEmpty()){
//                    std::cout << "Stack is currently empty" << std::endl;
//                } else {
//                    std::cout << "Stack is not empty" << std::endl;
//                }
//                break;
//            case 1:
//                if(stack.isEmpty()){
//                    std::cout << "Cannot pop! Stack in underflow state!" << std::endl;
//                } else {
//                    std::cout << "Popping " << stack.pop() << std::endl;
//                }
//                break;
//            case 2:
//                pushNum = rand() % 25;
//                if(stack.push(pushNum)){
//                    std::cout << "Pushed: " << pushNum << std::endl;
//                } else {
//                    std::cout << "Cannot push! Stack in overflow state!" << std::endl;
//                }
//                break;
//            case 3:
//                if(stack.peek() == -1){
//                    std::cout << "Stack is currently empty! Cannot peek!" << std::endl;
//                } else {
//                    std::cout << "Peeking: " << stack.peek() << std::endl;
//                }
//                break;
//        }
//    }

    return 0;
}