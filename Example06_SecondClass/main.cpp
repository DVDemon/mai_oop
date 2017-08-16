/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "SquareEquation.h"

int main(int argc, char** argv) {
    double a, b, c;

    std::cout << "Enter a:";
    std::cin >> a;

    std::cout << "Enter b:";
    std::cin >> b;

    std::cout << "Enter c:";
    std::cin >> c;

    SquareEquation se(a, b, c);
    //SquareEquation *ptr_se = new SquareEquation(a, b, c);
    

    std::cout << "X1=" << se.FindX1() << "\n";
    std::cout << "X2=" << se.FindX2() << "\n";
    
    //delete ptr_se;
    return 0;
}

