/* 
 * File:   SquareEquation.cpp
 * Author: dvdemon
 * 
 * Created on August 27, 2015, 8:39 AM
 */

#include "SquareEquation.h"
#include <math.h>
#include <iostream>

SquareEquation::SquareEquation(double a, double b, double c) {
    this->a = a;
    SquareEquation::b = b;
    this->c = c;
    double d = (b * b - 4 * a * c);
    if (d < 0) throw WrongEquationException(d);
}

double SquareEquation::FindX1() {
    double d = (b * b - 4 * a * c);
    return (-b - sqrt(d)) / (2 * a);
};

double SquareEquation::FindX2() {
    double d = (b * b - 4 * a * c);
    return (-b + sqrt(d)) / (2 * a);
};

SquareEquation::~SquareEquation(){
    std::cout << "Ura!!" << std::endl;
}
