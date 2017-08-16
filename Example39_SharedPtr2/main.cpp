#include <iostream>
#include <memory>

class A {
private:
    std::shared_ptr<A> next;
public:

    A() {
        std::cout << "I'm alive!" << std::endl;
    }
    
    A(A* next_ptr) : A(){
        next = std::shared_ptr<A>(next_ptr);
    }

    void DoSomething() {
        std::cout << "I'm busy!" << std::endl;
    }

    virtual ~A() {
        std::cout << "O no! I'am dead!" << std::endl;
    }
};

int main(int argc, char** argv) {

    std::shared_ptr<A> a(new A(new A(new A(new A()))));
    
    a.reset(new A());
    std::cout << "Done" << std::endl;
    return 0;
}

