/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

class A {
private:
    int _value;
public:

    A(int a) : _value(a) {
    };

    A operator()(int a) {
        std::cout << _value + a << std::endl;

        return A(_value + a);
    }
};

int main(int argc, char** argv) {

    A a(0);

    a(1)(1)(1)(1);

    a(0);
    
    return 0;
}

