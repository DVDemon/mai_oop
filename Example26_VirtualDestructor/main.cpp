#include <cstdlib>
#include <iostream>

class Parent {
public:

    virtual void foo() {
        std::cout << "Parent foo" << std::endl;
    }

    void A(){
       foo(); 
    }
    
     virtual ~Parent() {
        //foo();
        std::cout << "Parent" << std::endl;
    }
};

class Child : public Parent {
protected:
    char *ptr;
public:

    Child(){
        std::cout << "New" << std::endl;
        ptr = new char[1000];
    }
    void foo() {
        std::cout << "Child foo" << std::endl;
    }

    void foofoo(){
        
    }
    ~Child() {
        delete ptr;
        std::cout << "Child" << std::endl;
    }
};

int main(int argc, char** argv) {

    Child * a = new Child();
    
    Parent* ptr = (Parent*)a;
    //((Child*)ptr)->foofoo();
    //ptr->A();
    delete ptr;


    return 0;
}

