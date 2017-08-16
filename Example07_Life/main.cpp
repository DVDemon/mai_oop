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
    Life() { std::cout << "I'm alive" << std::endl;}
    Life(const char* n) : Life() { name=n; std::cout<< "My name is " << name << std::endl;};
    ~Life() { std::cout << "Oh no! I'm dead!" << std::endl;}
private:
    std::string name;
};

int main(int argc, char** argv) {

    Life a;
    {
        Life c("Nikodim");
    }
    Life b("Oleg");
    
    Life *d_ptr;
    
    d_ptr = new Life("Agafon");
    delete d_ptr;
    
    return 0;
}

