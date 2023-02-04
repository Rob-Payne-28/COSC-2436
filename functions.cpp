/*********************
Name: Robert Payne
Coding 02
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#include "functions.h"

void displayCircle(Circle *myCircle){
    std::cout << myCircle->getRadius() << std::endl;
    std::cout << myCircle->getDiameter() << std::endl;
    std::cout << myCircle->getCircumference() << std::endl;
    std::cout << myCircle->getArea() << std::endl;
    std::cout << std::endl;
}

void displayCylinder(Cylinder *myCylinder){
    std::cout << myCylinder->getRadius() << std::endl;
    std::cout << myCylinder->getDiameter() << std::endl;
    std::cout << myCylinder->getCircumference() << std::endl;
    std::cout << myCylinder->getArea() << std::endl;
    std::cout << myCylinder->getVolume() << std::endl;
    std::cout << std::endl;
}