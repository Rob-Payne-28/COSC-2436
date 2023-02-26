/*********************
Name: Robert Payne
Coding 05
Purpose: Assignment 05 - Stack program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char **argv) {

    int stackSize = STANDARD_SIZE;
    bool error = true;

    /************************************************
    ***************** INPUT TESTS *******************
    ************************************************/

    std::cout << "=====================================================" << std::endl;
    std::cout << "Beginning tests..." << std::endl << "Testing input..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    // if there are too few arguments, let the user know
    if (argc < 2) {
        std::cout << "Please enter a valid stack size as an argument to this program. Stack size must be an integer."
                  << std::endl;
        // if there are too many arguments, let the user know
    } else if (argc > 2) {
        std::cout
                << "You've provided too many arguments! This program is designed to take only one argument as an integer."
                << std::endl;
    } else {
        // if the program received a stack size, attempt to create the stack
        std::cout << "The requested stack size is: " << argv[1] << std::endl;
        try {
            // convert the string from the input to an integer and set the error condition to false so the
            // rest of the program operates
            stackSize = std::atoi(argv[1]);
            error = false;
        } catch (const std::invalid_argument &error) {
            // if the user provides a string instead of an integer, let the user know
            std::cout
                    << "You've provided an argument that is not an integer. This program is designed to take only one argument as an integer."
                    << std::endl;
        }

    }

    // Don't execute any other code if the stack size wasn't properly entered
    if (!error) {

        if(stackSize < 2){
            stackSize = DEFAULT_SIZE;
        }
        int testAmount = stackSize * TEST_MULTIPLIER;

        // Create stack using entered stack size
        Stack *stack = new Stack(stackSize);

        std::cout << "Created a stack with a size of " << stack->getSize() << std::endl;
        std::cout << std::endl;

        /************************************************
        ***************** EMPTY TESTS *******************
        ************************************************/

        std::cout << "=====================================================" << std::endl;
        std::cout << "Beginning tests..." << std::endl << "Testing empty operations..." << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << std::endl;

        std::cout << "Testing isEmpty on empty stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            if (stack->isEmpty()) {
                std::cout << " Stack is empty" << std::endl;
            } else {
                std::cout << " Stack is not empty" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing getSize on empty stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            std::cout << " Stack size: " << stack->getSize() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Testing peek on empty stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            Data peekedData;
            if (stack->peek(peekedData)) {
                std::cout << " Peeked element: " << std::endl;
                std::cout << "    id- " << peekedData.id << std::endl;
                std::cout << "    information- " << peekedData.information << std::endl;
            } else {
                std::cout << " Stack is empty - Cannot peek!" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing pop on empty stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            Data poppedData;
            if (stack->pop(poppedData)) {
                std::cout << " Popped element: " << std::endl;
                std::cout << "    id- " << poppedData.id << std::endl;
                std::cout << "    information- " << poppedData.information << std::endl;
            } else {
                std::cout << " Stack is empty - Cannot pop!" << std::endl;
            }
        }
        std::cout << std::endl;

        /************************************************
        *********** FILLING AND FULL TESTS *************
        ************************************************/

        std::cout << "=====================================================" << std::endl;
        std::cout << "Testing full operations..." << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << std::endl;

        std::cout << "Filling stack and testing push on overflow" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            int id = arc4random();
            std::string information;
            rand_string(&information);

            bool pushSuccess = stack->push(id, information);

            if (pushSuccess) {
                std::cout << " Pushed data with id " << id << " and information " << information << " onto the stack"
                          << std::endl;
            } else {
                std::cout << " Overflow Error: Failed to push data with id "
                          << id << " and information "
                          << information << " onto the stack"
                          << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing getSize on full stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            std::cout << " Stack size: " << stack->getSize() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Testing isEmpty() when full" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            if (stack->isEmpty()) {
                std::cout << " Stack is empty" << std::endl;
            } else {
                std::cout << " Stack is not empty" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing peek and pop on full stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            Data peekedData;
            if (stack->peek(peekedData)) {
                std::cout << " Peeked element: " << "id- " << peekedData.id << " information- "
                          << peekedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot peek!" << std::endl;
            }

            Data poppedData;
            if (stack->pop(poppedData)) {
                std::cout << " Popped element: " << "id- " << poppedData.id << " information- "
                          << poppedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot pop!" << std::endl;
            }
        }
        std::cout << std::endl;

        /************************************************
         *************** MID-STACK TESTS ****************
         ************************************************/

        std::cout << "=====================================================" << std::endl;
        std::cout << "Filling stack halfway and testing mid-stack operations..." << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << std::endl;

        std::cout << "Filling stack halfway" << std::endl;
        for (int i = 0; i < (testAmount / 2); ++i) {
            int id = arc4random();
            std::string information;
            rand_string(&information);

            bool pushSuccess = stack->push(id, information);

            if (pushSuccess) {
                std::cout << " Pushed data with id " << id << " and information " << information << " onto the stack"
                          << std::endl;
            } else {
                std::cout << " Overflow Error: Failed to push data with id "
                          << id << " and information "
                          << information << " onto the stack"
                          << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing getSize on mid-stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            std::cout << " Stack size: " << stack->getSize() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Testing isEmpty() on mid-stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            if (stack->isEmpty()) {
                std::cout << " Stack is empty" << std::endl;
            } else {
                std::cout << " Stack is not empty" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing peek, pop, and push on mid-stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            int id = arc4random();
            std::string information;
            rand_string(&information);

            bool pushSuccess = stack->push(id, information);

            if (pushSuccess) {
                std::cout << " Pushed data with id " << id << " and information " << information << " onto the stack"
                          << std::endl;
            } else {
                std::cout << " Overflow Error: Failed to push data with id "
                          << id << " and information "
                          << information << " onto the stack"
                          << std::endl;
            }

            Data peekedData;
            if (stack->peek(peekedData)) {
                std::cout << " Peeked element: " << "id- " << peekedData.id << " information- "
                          << peekedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot peek!" << std::endl;
            }

            Data poppedData;
            if (stack->pop(poppedData)) {
                std::cout << " Popped element: " << "id- " << poppedData.id << " information- "
                          << poppedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot pop!" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing peek and pop on mid-stack to empty" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            Data peekedData;
            if (stack->peek(peekedData)) {
                std::cout << " Peeked element: " << "id- " << peekedData.id << " information- "
                          << peekedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot peek!" << std::endl;
            }

            Data poppedData;
            if (stack->pop(poppedData)) {
                std::cout << " Popped element: " << "id- " << poppedData.id << " information- "
                          << poppedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot pop!" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing getSize on emptied stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            std::cout << " Stack size: " << stack->getSize() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Testing isEmpty() on emptied stack" << std::endl;
        for (int i = 0; i < testAmount; ++i) {
            if (stack->isEmpty()) {
                std::cout << " Stack is empty" << std::endl;
            } else {
                std::cout << " Stack is not empty" << std::endl;
            }
        }
        std::cout << std::endl;


        /************************************************
        ************** RANDOM ORDER TESTS ***************
        ************************************************/

        std::cout << "=====================================================" << std::endl;
        std::cout << "Executing operations in random order..." << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << std::endl;

        // clear stack
        while (!stack->isEmpty()) {
            Data poppedData;
            stack->pop(poppedData);
        }

        std::cout << "Filling stack halfway" << std::endl;
        for (int i = 0; i < (testAmount / 2); ++i) {
            int id = arc4random();
            std::string information;
            rand_string(&information);

            bool pushSuccess = stack->push(id, information);

            if (pushSuccess) {
                std::cout << " Pushed data with id " << id << " and information " << information << " onto the stack"
                          << std::endl;
            } else {
                std::cout << " Overflow Error: Failed to push data with id "
                          << id << " and information "
                          << information << " onto the stack"
                          << std::endl;
            }
        }
        std::cout << std::endl;

        int randNum = arc4random();
        int selection = std::abs(randNum) % POSSIBLE_SELECTIONS + 1;
        for (int i = 0; i < testAmount * 2; i++) {

            int id;
            std::string information;
            bool pushSuccess;
            Data data;

            switch (selection) {
                case 1:
                case 2:
                    id = arc4random();
                    rand_string(&information);

                    pushSuccess = stack->push(id, information);

                    if (pushSuccess) {
                        std::cout << " Pushed data with id " << id << " and information " << information
                                  << " onto the stack" << std::endl;
                    } else {
                        std::cout << " Overflow Error: Failed to push data with id "
                                  << id << " and information "
                                  << information << " onto the stack"
                                  << std::endl;
                    }
                    break;
                case 3:
                case 4:
                    if (stack->pop(data)) {
                        std::cout << " Popped element: " << "id- " << data.id << " information- "
                                  << data.information << std::endl;
                    } else {
                        std::cout << " Underflow error - Cannot pop!" << std::endl;
                    }
                    break;
                case 5:
                    if (stack->peek(data)) {
                        std::cout << " Peeked element: " << "id- " << data.id << " information- "
                                  << data.information << std::endl;
                    } else {
                        std::cout << " Underflow error - Cannot peek!" << std::endl;
                    }
                    break;
                case 6:
                    if (stack->isEmpty()) {
                        std::cout << " Stack is empty" << std::endl;
                    } else {
                        std::cout << " Stack is not empty" << std::endl;
                    }
                    break;
                case 7:
                    std::cout << " Stack size: " << stack->getSize() << std::endl;
                    break;
            }
            randNum = arc4random();
            selection = std::abs(randNum) % POSSIBLE_SELECTIONS + 1;

        }
        std::cout << std::endl;

        std::cout << "Finished testing without any unhandled errors!" << std::endl;
        std::cout << std::endl;

        std::cout << "Clearing stack..." << std::endl;
        while (!stack->isEmpty()) {
            Data poppedData;
            stack->pop(poppedData);
        }

        if (stack->isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            std::cout << "Stack is not empty" << std::endl;
        }

        std::cout << "Deleting stack..." << std::endl;
        delete stack;
    }

    return 0;
}