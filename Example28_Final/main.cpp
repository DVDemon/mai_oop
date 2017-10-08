#include <cstdlib>
#include <iostream>

class A{
public:
    virtual void foo() final{
        std::cout << "A" <<std::endl;
    }
    
    //void foofoo() final {} //error only for virtual methods
       
};

class B : public A{
public:
    void foo(){
        std::cout << "B" <<std::endl;
    }
    
};

int main(int argc, char** argv) {

    A* b=new B();
    b->foo();
    delete b;
    return 0;
}

