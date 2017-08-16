/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on August 11, 2015, 12:40 PM
 */

#include <cstdlib>
#include "Triangle.h"

int main(int argc, char** argv) {

    Figure *ptr = new Triangle(std::cin);
    ptr->Print();
    std::cout << ptr->Square() << std::endl;
    delete ptr;
    return 0;
}

