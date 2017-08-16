/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

class Life
{
public:
    Life() { }
    Life(const char* n) : Life() { name=n; };
    ~Life() {}
private:
    std::string name;
};

int main(int argc, char** argv) {

    Life a("Ivan"),b("Ivan");
    
    std::cout << "Is Equal pointers:" << (&a==&b) << std::endl;
    
    Life *ptr = &a;
    std::cout << "Is Equal pointers:" << (ptr==&a) << std::endl;
    ptr= &b;
    std::cout << "Is Equal pointers:" << (ptr==&a) << std::endl;
    
    //std::cout << "Is Equal:" << (a==b) << std::endl; // Error no operator == defined!
    
    return 0;
}

