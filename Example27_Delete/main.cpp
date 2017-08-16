#include <cstdlib>
#include <iostream>

class X{
private:
    int i;
public:
    X(int value) : i(value) {};
    
    //X& operator= (const X&) = delete;
    //X(const X&) = delete;
    
};

int main(int argc, char** argv) {

    X a(1);
    X b=a;
    
    b = a;
    
    return 0;
}

