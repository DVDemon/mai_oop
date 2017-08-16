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
    Rectangle rec1(1,2);
    Rectangle rec2(2,1);
    
    std::cout << rec1 << rec2 << (rec1+rec2) << std::endl;
    
    Rectangle result = rec1+rec2;
    std::cout << result;
    
    return 0;
}

