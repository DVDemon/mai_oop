#include <cstdlib>
#include <iostream>
#include <memory>
#include <thread>

class A {
private:
    const char* name;
public:

    A(const char* value) : name(value) {
        std::cout << "I'm alive!" << std::endl;
    }
    
    A(const A& a){
        std::cout << "I have been cloned!" << std::endl;
    }

    void WhoAmI() {
        std::cout << name << std::endl;
    }

    virtual ~A() {
        std::cout << "O no! I'am dead!" << std::endl;
    }
};

int main(int argc, char** argv) {

    std::shared_ptr<A> a(new A("My name is A"));
    std::shared_ptr<A> b(new A("My name is B"));
    
    std::swap(a,b);
    
    a->WhoAmI();
    b->WhoAmI();
    
    return 0;
}

