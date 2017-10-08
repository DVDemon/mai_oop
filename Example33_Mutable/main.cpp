#include <cstdlib>
#include <iostream>

class A{
private:
    const int VALUE = 7;
     int counter = 0;
public:
    const int get() const{
        counter++;
        return VALUE;
    }
    
    const int get_counter() const{
        return counter;
    }
};

int main(int argc, char** argv) {

    A a;
    std::cout<< a.get() << std::endl;
    std::cout<< a.get() << std::endl;
    std::cout<< a.get() << std::endl;
    std::cout<< a.get_counter() << std::endl;
    
            
    return 0;
}

