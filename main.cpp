/*********************
Name: Robert Payne
Coding 02
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    Circle myCircle1;
    Circle myCircle2(10);

    Cylinder myCylinder1;
    Cylinder myCylinder2(10, 20);

    displayCircle(&myCircle1);
    displayCircle(&myCircle2);

    displayCylinder(&myCylinder1);
    displayCylinder(&myCylinder2);

    return 0;
}