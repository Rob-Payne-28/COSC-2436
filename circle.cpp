/*********************
Name: Robert Payne
Coding 02
Purpose: Assignment 03 - "Classes and Objects" program that is part of COSC-2436.
**********************/

#include "circle.h"

Circle::Circle() {
    setRadius(MIN);
}

Circle::Circle(double radius) {
    setRadius(radius);
}

Circle::~Circle() {
}

double Circle::getRadius() {
    return radius;
}

double Circle::getDiameter() {
    return radius * 2.0;
}

double Circle::getCircumference() {
    return 2 * PI * radius;
}

double Circle::getArea() {
    return PI * pow(radius, 2);
}

void Circle::setRadius(double customRadius) {
    if (customRadius > MIN) {
        radius = customRadius;
    } else {
        radius = MIN;
    }
}
