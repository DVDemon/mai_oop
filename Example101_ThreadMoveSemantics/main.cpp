#include <thread>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Param {
protected:
    std::string str;
public:
    Param() = delete;
    Param(const Param &other) = delete;

    Param(const char* value) : str(value) {
        std::cout << "Param Constructor:" << str << std::endl;
    }
    Param & operator=(const Param& other) = delete;

    friend std::ostream& operator<<(std::ostream &os,Param &param);
    virtual ~Param() {
        std::cout << "Param Destructor" << std::endl;
    }

};

std::ostream& operator<<(std::ostream &os,Param &param){
  return os << param.str;    
}

class MyClass {
protected:
    std::unique_ptr<Param> ptr;
public:

    MyClass( std::unique_ptr<Param> &&param) {
        ptr = std::move(param);
        std::cout << "My Class Constructor" << std::endl;
    }

    MyClass(MyClass &&other) {
        ptr = std::move(other.ptr);
        std::cout << "My Class Moved" << std::endl;
    }

    MyClass(const MyClass &) = delete;
    MyClass & operator=(const MyClass &)= delete;
    
    void operator()() {
        std::cout << *ptr << std::endl;
    }

};

int main() {

    std::thread my_thread(std::move(
                          MyClass(std::move(
                                  std::unique_ptr<Param>(
                                     new Param("Hello world!"))))));
    my_thread.join();
    
    return 0;
}

