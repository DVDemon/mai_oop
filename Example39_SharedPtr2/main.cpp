#include <iostream>
#include <memory>

class A {
private:
    std::shared_ptr<A> next; // 
    //A* next;
public:

    A() {
        std::cout << "I'm alive!" << std::endl;
    }
    
    A(A* next_ptr) : A(){
        std::cout << "O_o ";

        next = std::shared_ptr<A>(next_ptr);
        //next = next_ptr;
    }

    void DoSomething() {
        std::cout << "I'm busy!" << std::endl;
    }

    virtual ~A() {
        std::cout << "O no! I'am dead!" << std::endl;
    }
};

int main(int argc, char** argv) {

    try{
    std::shared_ptr<A> a(new A(new A(new A(new A()))));
    }catch(...){
        
    }
    //a.reset();
    std::cout << "Done" << std::endl;
    return 0;
}

