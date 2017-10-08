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

    A& operator()(int a) {
        std::cout << _value + a << std::endl;
        _value+=a;
        return *this;
    }
    A& operator()(int a,int b) {
        std::cout << _value + a +b << std::endl;
        _value+=a+b;
        return *this;
    }
    A& operator++(int){
        _value++;
        return *this;
    }
};

int main(int argc, char** argv) {

    A a(0);

    a(1)++(2)++(4)++(8,2);

    //for(int i=0;i<10;i++) a(1);

    a(0);
    
    return 0;
}

