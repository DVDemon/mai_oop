/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "Rectangle.h"

int main(int argc, char** argv) {
    Rectangle rec(10,2);
    
    ++(((rec++)++)++);

    std::cout << "Width=" << rec[0] << " Height=" << rec[1] << std::endl;
    std::cout << "Square=" << rec << std::endl;
    
    
    return 0;
}

