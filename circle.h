/*********************
Name: Robert Payne
Coding 03
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/


#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#include <math.h>

#define MIN 0
#define PI 3.141592

class Circle {

public:
    // Constructors/Deconstructor
    Circle();
    Circle(double);
    ~Circle();

    // Getters
    double getRadius();
    double getDiameter();
    double getCircumference();
    double getArea();

    // Setters
    void setRadius(double);

protected:
    double radius;
};

#endif //CLASSES_CIRCLE_H
