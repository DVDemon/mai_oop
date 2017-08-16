#include <iostream>

template <class T> void print(const T& t) {
    std::cout << t << std::endl;
}

template <class First, class... Rest> 
   void print(const First& first, const Rest&... rest) {
    std::cout << first << ", ";
    print(rest...); // рекурсия на стадии компиляции!
}

template <class T> T add(const T t) {
    return t;
}

template <class First, class... Rest> First add(const First first, const Rest... rest) {
    return first + (First) add(rest...); // recursive call using pack expansion syntax
}

int main(int argc, char** argv) {
    std::cout << add(1, 2, 2.1, 100.0) << std::endl;

    
    print(10, 20);
    print(100, 200, 300);
    print<int, double, int>(1, 2.0, 3);
    print("first", 2, "third", 3.14159);
    
    
    return 0;
}

