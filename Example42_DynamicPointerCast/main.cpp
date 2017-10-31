#include <cstdlib>
#include <iostream>
#include <memory>



class A {
public:
        A(){};
        virtual void Do(){
            std::cout << "A" << std::endl;
        }
};

class B : public A {
public:
    B(){ b = 1;};
    void Do() override {
        std::cout << "B" << std::endl; 
    }

    void DoB() {
        std::cout << "B second function" << std::endl; 
    }

    int b;
};

class C : public A {
public:
    C(){c="Hello!";};
    void Do() override {
        std::cout << "C" << std::endl; 
    }
    void DoC()  {
        std::cout << "C second function" << std::endl; 
    }

    const char* c;
};


int main(int argc, char** argv) {


    std::shared_ptr<B> b(new B());
    std::shared_ptr<C> c(new C());

    std::shared_ptr<A> ptr = b;

    if(std::shared_ptr<B> ptr_b = std::dynamic_pointer_cast<B>(ptr)){
        ptr_b->Do();
    }

    if(std::shared_ptr<C> ptr_c = std::dynamic_pointer_cast<C>(ptr)){
        ptr_c->Do();
    } else std::cout << "Oops" << std::endl;
    
    return 0;
}

