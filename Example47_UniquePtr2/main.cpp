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

int main(int argc, char** argv) {
    std::unique_ptr<A> a(new A("My name"));
    //std::unique_ptr<A> b(a); // no copy constructor
    std::unique_ptr<A> c;
    //c=a; // no copy operator

    c= std::move(a);
    //c->Print();
    a->Print();
    
    return 0;
}

