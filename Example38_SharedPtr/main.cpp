#include <cstdlib>
#include <iostream>
#include <memory>

class A {
public:

    A() {
        std::cout << "I'm alive!" << std::endl;
    }
    
    A(const A& a){
        std::cout << "I have been cloned!" << std::endl;
    }

    void DoSomething() {
        std::cout << "I'm busy!" << std::endl;
    }

    virtual ~A() {
        std::cout << "O no! I'am dead!" << std::endl;
    }
};

void Foo(std::shared_ptr<A> &a) {
    std::cout << "Usage count:" << a.use_count() << std::endl;
    std::shared_ptr<A> b(a);
    std::cout << "Usage count:" << a.use_count() << std::endl;
    a->DoSomething();
    b->DoSomething();
}

int main(int argc, char** argv) {

    std::shared_ptr<A> a(new A());
    std::cout << "Usage count:" << a.use_count() << std::endl;
    Foo(a);
    std::cout << "Usage count:" << a.use_count() << std::endl;
    return 0;
}

