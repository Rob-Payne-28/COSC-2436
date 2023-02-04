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

double Cylinder::getRadius() {
    return radius;
}

double Cylinder::getHeight() {
    return height;
}

double Cylinder::getVolume() {
    return 0; // TODO: figure this equation out
}

double Cylinder::getArea() {
    return 0; // TODO: figure this equation out
}

void Cylinder::setHeight(double customHeight) {
    if(customHeight > MIN) {
        height = customHeight;
    } else {
        height = MIN;
    }
}