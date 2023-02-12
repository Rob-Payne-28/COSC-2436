/*********************
Name: Robert Payne
Coding 04
Purpose: Assignment 04 - Simple Int Stack program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    // Generates a random seed for random testing
    srand(time(NULL));

    // Create stack
    std::cout << "Creating stack with size of " << SIZE << "..." << std::endl;
    Stack stack(SIZE);

    // Since the constructor will not accept any value less than 2, I had to make sure the testing
    // also handled that condition. This ensures that the testing is based off of the stack size
    // even if the stack size is overridden by the constructor to the default value of 10.
    int stackSize = SIZE;
    if(stackSize < 2){
        std::cout << " Stack below minimum size. Falling back to default stack size of 10." << std::endl;
        stackSize = 10;
    }
    std::cout << std::endl;

    // Also checked the input of the number of tests to run. If it is below 1, default to 1 run.
    std::cout << "Checking TEST_RUNS..." << std::endl;
    int numberOfTestsToRun = TEST_RUNS;
    if(numberOfTestsToRun < 1){
        std::cout << " TEST_RUNS below minimum size. Falling back to minimum of 1." << std::endl;
        numberOfTestsToRun = 1;
    }
    std::cout << std::endl;

    // Test isEmpty function when empty
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
        std::cout << " Pushed " << i << " onto stack" << std::endl;
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
    for (int i = 0; i < numberOfTestsToRun; ++i) {
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
    for (int i = 0; i < numberOfTestsToRun; ++i) {
        try {
            std::cout << " Popping: " << stack.pop() << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Tests peek in underflow
    std::cout << "Testing peek in underflow" << std::endl;
    for (int i = 0; i < numberOfTestsToRun; ++i) {
        try {
            std::cout << " Peeking: " << stack.peek() << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << " " << error.what() << std::endl;
        }
    }
    std::cout << std::endl;

    // Runs tests in random order. Number of times run is adjusted with the TEST_RUNS directive.
    // Will default to 1 test run if TEST_RUNS is below 1.
    std::cout << "Testing methods in a random order" << std::endl;
    for (int i = 0; i < numberOfTestsToRun; ++i) {
        // Generates random number with 4 possible outcomes (0-3)
        int randomNum = rand() % 4;

        // Used as a random number to push onto the stack in case 2.
        int pushNum;
        switch (randomNum) {
            case 0:
                if(stack.isEmpty()){
                    std::cout << " Stack is empty" << std::endl;
                } else {
                    std::cout << " Stack is not empty" << std::endl;
                }
                break;
            case 1:
                try {
                    std::cout << " Popping " << stack.pop() << " off of stack" << std::endl;
                } catch (const std::runtime_error& error) {
                    std::cerr << " " << error.what() << std::endl;
                }
                break;
            case 2:
                pushNum = INT_MIN + rand() % RANGE;
                try {
                    stack.push(pushNum);
                } catch (const std::runtime_error& error) {
                    std::cerr << " " << error.what() << std::endl;
                }
                std::cout << " Pushed " << pushNum << " onto stack" << std::endl;
                break;
            case 3:
                try {
                    std::cout << " Peeking " << stack.peek() << " on stack" << std::endl;
                } catch (const std::runtime_error& error) {
                    std::cerr << " " << error.what() << std::endl;
                }
                break;
        }
    }
    std::cout << std::endl;

    std::cout << "Program completed without any unhandled exceptions!" << std::endl;

    return 0;
}
