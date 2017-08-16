/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

class Rectangle{
public:
    unsigned long width,height;
     Rectangle(int w,int h) : width(w),height(h) {};
};

 Rectangle operator "" _rect (unsigned long long w){
    return Rectangle(w,w);
}

class Kg{
public:
    std::string number;
    Kg(const char* str) : number(str) {};
};
  Kg operator "" _kg (const char* str){
    return Kg(str);
}


int main(int argc, char** argv) {
    Rectangle a=12_rect;
    
    std::cout << "Width=" << (10_rect).width << std::endl;
    std::cout << (3_kg).number;
    return 0;
}

