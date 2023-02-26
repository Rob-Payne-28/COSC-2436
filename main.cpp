/*********************
Name: Robert Payne
Coding 05
Purpose: Assignment 05 - Stack program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char **argv) {
    // ToDo: Get rid of this if you don't use it
    srand(time(NULL));


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
    if(argc < 2) {
        std::cout << "Please enter a valid stack size as an argument to this program. Stack size must be an integer." << std::endl;
    // if there are too many arguments, let the user know
    } else if(argc > 2){
        std::cout << "You've provided too many arguments! This program is designed to take only one argument as an integer." << std::endl;
    } else {
        // if the program received a stack size, attempt to create the stack
        std::cout << "The requested stack size is: " << argv[1] << std::endl;
        try{
            // convert the string from the input to an integer and set the error condition to false so the
            // rest of the program operates
            stackSize = std::atoi(argv[1]);
            error = false;
        } catch(const std::invalid_argument& error){
            // if the user provides a string instead of an integer, let the user know
            std::cout << "You've provided an argument that is not an integer. This program is designed to take only one argument as an integer." << std::endl;
        }

    }

    // Don't execute any other code if the stack size wasn't properly entered
    if (!error) {

        Stack* stack = new Stack(stackSize);

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
        for (int i = 0; i < TEST_AMOUNT; ++i) {
            if (stack->isEmpty()) {
                std::cout << " Stack is empty" << std::endl;
            } else {
                std::cout << " Stack is NOT empty" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing peek on empty stack" << std::endl;
        for (int i = 0; i < TEST_AMOUNT; ++i) {
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
        for (int i = 0; i < TEST_AMOUNT; ++i) {
            Data poppedData;
            if (stack->pop(poppedData)) {
                std::cout << " Popped element: " << std::endl;
                std::cout << "    id- " << poppedData.id << std::endl;
                std::cout << "    information- " << poppedData.information << std::endl;
            } else {
                std::cout << " Stack is empty - Cannot pop!" << std::endl;
            }
        }

        /************************************************
        *********** FILLING AND FULL TESTS *************
        ************************************************/

        std::cout << "=====================================================" << std::endl;
        std::cout << "Testing full operations..." << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << std::endl;

        std::cout << "Filling stack and testing push on overflow" << std::endl;
        for (int i = 0; i < TEST_AMOUNT; ++i) {
            int id = arc4random();
            std::string information;
            rand_string(&information);

            bool pushSuccess = stack->push(id, information); // call the push method on the stack instance

            if (pushSuccess) {
                std::cout << " Pushed data with id " << id << " and information " << information << " onto the stack" << std::endl;
            } else {
                std::cout << " Overflow Error: Failed to push data with id "
                << id << " and information "
                << information << " onto the stack"
                << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing isEmpty() when full" << std::endl;
        for (int i = 0; i < TEST_AMOUNT; ++i) {
            if (stack->isEmpty()) {
                std::cout << " Stack is empty" << std::endl;
            } else {
                std::cout << " Stack is NOT empty" << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "Testing peek and pop on full stack" << std::endl;
        for (int i = 0; i < TEST_AMOUNT; ++i) {
            Data peekedData;
            if (stack->peek(peekedData)) {
                std::cout << " Peeked element: " << "id- " << peekedData.id << "information- " << peekedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot peek!" << std::endl;
            }

            Data poppedData;
            if (stack->pop(poppedData)) {
                std::cout << " Popped element: " << "id- " << poppedData.id << "information- " << poppedData.information << std::endl;
            } else {
                std::cout << " Underflow error - Cannot pop!" << std::endl;
            }
        }
//
//        std::string strtemp;
//        rand_string(&strtemp);
//        std::cout << strtemp << std::endl;
//



    }
    /* ***************************************************************
     * Throughly test your stack. You must perform an exhaustive series
     * of tests on your stack. Show all possible ways your stack can be used
     * and abused and prove that your stack can gracefully handle ALL cases.
     * You must use automated testing (no user input). First cover all
     * explicit cases which you can think of, then execute random operations.
     * When generating test data, use random ints for ids and random short
     * strings for string. There is a string generator made for you in the
     * functions module. You are free to use it or make your own.
     * ***************************************************************/

    /* ***************************************************************
     * Below is some sample code for the random string function. It's
     * only here to demonstrate the function. DELETE it once you study
     * it and understand it and can use it yourself in your code.
     * ***************************************************************/

    
    /* ***************************************************************
     * Your code will be tested by applying your stack to a custom main
     * designed to break your code. If it can be broken, you risk a
     * substantially reduced grade, up to and including a zero.
     * ***************************************************************/
    
    // WHEN YOU SUBMIT, DELETE ALL THESE INSTRUCTIONALCOMMENTS
    
    return 0;
}
