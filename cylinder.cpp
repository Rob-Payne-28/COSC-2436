/*********************
Name: Robert Payne
Coding 02
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#include "cylinder.h"

Cylinder::Cylinder() {
    setRadius(MIN);
    setHeight(MIN);
}

Cylinder::Cylinder(double customRadius, double customHeight) {
    setRadius(customRadius);
    setHeight(customHeight);
}

Cylinder::~Cylinder() {
}

double Cylinder::getHeight() {
    return height;
}

double Cylinder::getArea() {
    return (2 * PI * radius * height) + (2 * PI * radius * radius);
}

double Cylinder::getVolume() {
    return PI * (radius * radius) * height;
}

void Cylinder::setHeight(double customHeight) {
    if (customHeight > MIN) {
        height = customHeight;
    } else {
        height = MIN;
    }
}
