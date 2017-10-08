#include <cstdlib>
#include <iostream>


class B{
public:
    void fooB(){
        
    }
};

class A{
public:
    int a;
    void fooA(B b) const{
        b.fooB();
        fooA2();
        //a=7;
    }
    
    void fooA2() const{
        
    }
};




int main(int argc, char** argv) {

    A a;
    B b;
    a.fooA(b);
    return 0;
}

