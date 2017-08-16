/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

class B {
public:
     virtual void foo(short) {
        std::cout << "B::foo" << std::endl;
    }
};

class D : public B {
public: 
     void foo(short)  override {
        std::cout << "D::foo" << std::endl;
    }
};

class E {
public:
    virtual void foo(int) {
        std::cout << "E::foo" << std::endl;
    } // try to remove const and add final
};

class F : public E {
public:
    void foo(short)  {
        std::cout << "F::foo" << std::endl;
    }
};

int main(int argc, char** argv) {

    F *f = new F();
    f->foo(2);
    ((E*)f)->foo(3);
    E* e = f;
    e->foo(2);
    delete f;


    D *d = new D();
    d->foo(1);
    B* b = d;
    b->foo(1);

    delete d;
    return 0;
}

