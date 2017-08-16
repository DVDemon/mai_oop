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

void deleter(A *a){
    std::cout << "Nobody kills in my ship!" << std::endl;
}
int main(int argc, char** argv) {

    A a("My name is A");
    std::shared_ptr<A> a_ptr(&a,&deleter);
    //std::shared_ptr<A> a_ptr(&a);
    std::shared_ptr<A> c();
    
    return 0;
}

