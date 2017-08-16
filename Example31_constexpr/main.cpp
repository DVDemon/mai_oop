#include <cstdlib>
#include <iostream>

constexpr int One(){
    return 1;
}
constexpr int all(int a,int b) {
    return (a| b) + One();
};



int main(int argc, char** argv) {

    int value;
    std::cin >> value;

    
    switch(value)
    {
        case 0: std::cout << "Zero" << std::endl;break;
        case 1: std::cout << "One" << std::endl;break;
        case 2: std::cout << "Two" << std::endl;break;
        case all(1,2) : std::cout << "All" << std::endl;break;
    }
    
    
    return 0;
}

