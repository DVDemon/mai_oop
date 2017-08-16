#include <iostream>
#include <cstdlib>
#include <memory>

class A {
private:
    const char* name;
public:

    A(const char*value) : name(value) {
    };

    void Print() {
        std::cout << name << std::endl;
    }

    virtual ~A() {
        std::cout << "A die: " << name << std::endl;
    }
};

class B : public  A {
public:

    B(const char*value) : A(value) {};

    virtual ~B() {
        std::cout << "B die!" << std::endl;
    }
};

int main(int argc, char** argv) {

    {
    std::shared_ptr<A> b(new B("My name is B!")); // This is A
    b->Print();
    }
    
    {
     std::shared_ptr<B> b(new B("My name is B!")); // This is B
     b->Print();
    }
    
    return 0;
}

