/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

class A {
public:

    A() {
        std::cout << "Created" << std::endl;
    }

    A(int a) : A() {
        value = a;
    }
    
    A(const A &a) :A() { value= a.value;}
    int value;

};

void over(A &a) {    std::cout << "LValue:" << a.value << std::endl;}

void over(A &&a) {   std::cout << "RValue:" << a.value << std::endl;}

void cross(A a) {   std::cout << "Copy:" << a.value << std::endl;}

int main(int argc, char** argv) {

    A a(5);
    //over(a);
    //over(A(7));
    
    cross(a);



    return 0;
}

