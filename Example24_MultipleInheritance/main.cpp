/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

class Z {
public:

    void Foo() {
        std::cout << "Hello from Z!\n";
    }
};

class A : public Z {
public:

    void FooA() {
        std::cout << "Hello from A!\n";
    }
};

class B : public Z {
public:

    void FooB() {
        std::cout << "Hello from B!\n";
    }
};

class C : public A, public B {
public:
//*
    void Foo() {
        std::cout << "Hello from C!\n";
    } // Try to comment!
 //* */
};

int main(int argc, char** argv) {
    C* c = new C();
    c->Foo();
    /* //Try to uncomment
    Z* z = (Z*)c; 
    z->Foo();
    //*/
    c->FooA();
    c->FooB();

    delete c;
    return 0;
}

