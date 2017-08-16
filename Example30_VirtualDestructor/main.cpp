#include <cstdlib>
#include <iostream>

class A {
public:

    virtual void foo() {
        std::cout << "A";
    }

    virtual ~A() {
        foo();
    }

};

class B : public A {
public:
    virtual void foo() {
        std::cout << "B";
    }
/*
    ~B() {
        foo();
    }
 */
};

int main(int argc, char** argv) {

    B b;

    return 0;
}

