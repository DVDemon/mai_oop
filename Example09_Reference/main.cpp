/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

void swap(int &a, int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}

int main(int argc, char** argv) {
    
    int a=10,b=20;
    swap(10,b);
    
    std::cout << "a=" << a << " ,b=" << b << std::endl;

    return 0;
}

