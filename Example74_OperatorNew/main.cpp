#include <stdlib.h>
#include <iostream>

class A {
private:
    int value;
public:

    A(int val) : value(val) {
         std::cout << "Constructor" << std::endl;
    };

    void *operator new(size_t size);
    void *operator new(size_t size,const char *msg);
    
    void operator delete(void *p);
    virtual ~A(){
        std::cout << "Destructor" << std::endl;
    }
};

void *A::operator new(size_t size,const char *msg) {
    std::cout << "Message :" << msg << std::endl;
    return malloc(size);
}

void *A::operator new(size_t size) {
    std::cout << "Allocated :" << size << "bytes" << std::endl;
    return malloc(size);
}

void A::operator delete(void *p) {
    std::cout << "Deleted" << std::endl;
    free(p);
}

int main() {

    {
        A a(1); // Тут не вызывается new!
        std::cout << "Inner block" << std::endl;
    }
    
    std::cout << std::endl << "Dynamic memory allocation" << std::endl;
    
    A* b = new("Hello world!") A(2);
    delete b;

    return 0;
}
