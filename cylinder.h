/*********************
Name: Robert Payne
Coding 02
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class Cylinder : public Circle {

public:
    // Constructors/Deconstructor
    Cylinder();
    Cylinder(double, double);
    ~Cylinder();

    // Getters
    double getHeight();
    double getArea();
    double getVolume();

    // Setters
    void setHeight(double);

private:
    double height;
};

#endif //CYLINDER_H
