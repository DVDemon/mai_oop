/* 
 * File:   Rectangle.cpp
 * Author: dvdemon
 * 
 * Created on August 29, 2015, 4:59 PM
 */

#include "Rectangle.h"
#include <iostream>
#include <cstdlib>

Rectangle::Rectangle(int w, int h) : _width(w), _height(h) {
}

Rectangle& Rectangle::operator++() {
    ++_width;
    ++_height;

    return *this;
}

Rectangle& Rectangle::operator++(int) {
    std::cout << "Postfix" << std::endl;
    _width++;
    _height++;
    return *this;

}

int Rectangle::operator[](int i) {
    switch (i) {
        case 0: return _width;
        case 1: return _height;
        default:
            std::exit(-1);
            break;
    }
}

Rectangle::operator int() {
    return _width*_height;

}

void Rectangle::print() {
    std::cout << "[" << _width << "," << _height << "]" << std::endl;
}

Rectangle::~Rectangle() {
}

