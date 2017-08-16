#include <cstdlib>
#include <iostream>

namespace MyNameSpace{
    int value = 0;
}

int value = 0;

int main(int argc, char** argv) {

    MyNameSpace::value = 7;
    std::cout << value << std::endl;
    std::cout << MyNameSpace::value << std::endl;
    
    using namespace MyNameSpace;
    //std::cout << value << std::endl; 
    return 0;
}

