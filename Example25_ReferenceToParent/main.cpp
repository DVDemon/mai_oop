#include <cstdlib>
#include <iostream>

class Parent{
public:
    void Foo(){
        std::cout << "Parent - Foo" << std::endl;
    }
};

class Child : public Parent{
public:
    void MyFoo(){
        Foo();
        std::cout << "Child - MyFoo" << std::endl;
    }
    
    void Foo(){
        Parent::Foo();
        std::cout << "Child - Foo" << std::endl;
    }
};


int main(int argc, char** argv) {

    Child a;
    a.MyFoo();
    
    return 0;
}

