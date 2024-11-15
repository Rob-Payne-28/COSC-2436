/*********************
Name: Robert Payne
Coding 03
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#include "functions.h"

// Calls the getters on a circle and displays their values
void displayCircle(Circle *myCircle){
    std::cout << "Diplaying Circle- " << std::endl;
    std::cout << " Radius: " << myCircle->getRadius() << std::endl;
    std::cout << " Diameter: " << myCircle->getDiameter() << std::endl;
    std::cout << " Circumference: " << myCircle->getCircumference() << std::endl;
    std::cout << " Area: " << myCircle->getArea() << std::endl;
    std::cout << std::endl;
}

// Calls the getters on a cylinder and displays their values
void displayCylinder(Cylinder *myCylinder){
    std::cout << "Displaying Cylinder- " << std::endl;
    std::cout << " Radius: " << myCylinder->getRadius() << std::endl;
    std::cout << " Height: " << myCylinder->getHeight() << std::endl;
    std::cout << " Diameter: " << myCylinder->getDiameter() << std::endl;
    std::cout << " Circumference: " << myCylinder->getCircumference() << std::endl;
    std::cout << " Area: " << myCylinder->getArea() << std::endl;
    std::cout << " Volume: " << myCylinder->getVolume() << std::endl;
    std::cout << std::endl;
}
