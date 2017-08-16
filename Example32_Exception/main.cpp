/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "SquareEquation.h"
#include "WrongArgumentException.h"

int main(int argc, char** argv) {
    double a, b, c;

    std::cout << "Enter a:";
    std::cin >> a;

    std::cout << "Enter b:";
    std::cin >> b;

    std::cout << "Enter c:";
    std::cin >> c;

    try{
    SquareEquation se(a, b, c);
    
    std::cout << "X1=" << se.FindX1() << "\n";
    std::cout << "X2=" << se.FindX2() << "\n";
    
    }catch(WrongArgumentException &ex){
        std::cout << "Exception in runtime:" << ex.what() << std::endl;
    }
    
    return 0;
}

