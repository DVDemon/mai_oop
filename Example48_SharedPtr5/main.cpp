#include <iostream>
#include <cstdlib>
#include <memory>
#include <exception>

class A {
private:
    const char* name;
public:

    A(const char*value) : name(value) {
        std::cout << name << std::endl;
    };

    virtual ~A() {
        std::cout << "I'm die: " << name << std::endl;
    }
};

int foofoofoo(){
    std::cout << "foofoofoo()" << std::endl;
    throw std::exception();
}

void foo(int,std::shared_ptr<A> a){
  std::cout << "foo()" << std::endl;  
}

int main(int argc, char** argv) {

    try{
        
    //*
    A *a=new A("A");
    foo(foofoofoo(),std::shared_ptr<A>(a));
    /*/
    std::shared_ptr<A> a(new A("B"));
    foo(foofoofoo(),a);
    
    //*/
    
    }catch(...){
        
    }
    
    return 0;
}

