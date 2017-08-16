/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

#include "Triangle.h"
#include "TStackItem.h"
#include "TStack.h"

// Simple stack on pointers

int main(int argc, char** argv) {

    Triangle a;
/*
    std::cin >> a;
    std::cout << a;

    ++a;

    std::cout << a;

    Triangle b = a;
    b = b + a;

    std::cout << b;
*/
    TStack stack;

    stack.push(Triangle(1, 1, 1));
    stack.push(Triangle(2, 2, 2));
    stack.push(Triangle(3, 3, 3));

    std::cout << stack;


    Triangle t;

    t = stack.pop();
    std::cout << t;
    t = stack.pop();
    std::cout << t;
    t = stack.pop();
    std::cout << t;

    return 0;
}

