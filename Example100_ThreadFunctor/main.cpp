#include <thread>
#include <iostream>

class MyClass{
public:
    MyClass() {
        std::cout << "Constructor" << std::endl;
    }

    MyClass(const MyClass& other) {
        std::cout << "Copy" << std::endl;
    }

    void operator()(const char* param) {
        std::cout << param << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    std::thread my_thread(MyClass(),"Hello world!");
    my_thread.join();
    return 0;
}

