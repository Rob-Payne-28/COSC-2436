/*********************
Name: Robert Payne
Coding 03
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    // Create a circle with MIN attributes, one that checks defaults to MIN when given a negative value, and
    // one with an entered value
    Circle myCircle1;
    Circle myCircle2(-10);
    Circle myCircle3(10);

    // Create a cylinder with MIN attributes, one that checks that defaults to MIN when given a negative value, and
    // one with entered values
    Cylinder myCylinder1;
    Cylinder myCylinder2(-10, -20);
    Cylinder myCylinder3(10, 20);

    // Pass all three circles to the display circle function to be printed
    displayCircle(&myCircle1);
    displayCircle(&myCircle2);
    displayCircle(&myCircle3);

    // Pass all three cylinders to the display cylinder function to be printed
    displayCylinder(&myCylinder1);
    displayCylinder(&myCylinder2);
    displayCylinder(&myCylinder3);

    return 0;
}
