/*********************
Name: Robert Payne
Coding 02
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/


#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#define MIN 0.0
#define PI 3.141592

class Circle {

public:
    Circle();

    Circle(double);

    ~Circle();

    double getCircumference();
    double getRadius();
    double getDiameter();
    double getSurfaceArea();

    void setCircumference(double);
    void setRadius(double);

protected:
    double circumference, radius;
};


#endif //CLASSES_CIRCLE_H
