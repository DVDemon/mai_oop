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

A* unsafe_function(){
    A* a = new A("I'm, only one!");
    return a;
    
}

std::unique_ptr<A> safe_function(){
    std::unique_ptr<A> a(new A("I'm, only one!"));
    return a;
}

int main(int argc, char** argv) {
    
    std::unique_ptr<A> a=safe_function();
    std::unique_ptr<A> b=a;
    
    //A* a = unsafe_function();
    a->Print();
    
    return 0;
}

