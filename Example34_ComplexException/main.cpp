#include <iostream>
#include <exception>

class MyException : public std::exception {
public:
    int A;

    MyException(int a) : std::exception(), A(a) {
        std::cout << "Exception constructed\n";
    }

    MyException(const MyException & other) : std::exception(other) {
        A = other.A;
        std::cout << "Copy exception constructed" << std::endl;
    }

    virtual ~MyException() {
        std::cout << "Exception destructed" << std::endl;
    };
};

void proc2(void) {
    try {

        std::cout << "Proc2 called" << std::endl;
        std::string().at(1); // this generates an std::out_of_range
        //throw 7; //custom class
        //throw MyException(100);

    } catch (int ex1) {
        std::cout << "int in Proc2" << std::endl;

    } catch (MyException& ex) {
        std::cout << "MyException in Proc2: " << ex.A << std::endl;
        std::exception_ptr currentException = std::make_exception_ptr(ex);
        std::rethrow_exception(currentException);
        
    } catch (...) {
        std::exception_ptr currentException = std::current_exception();
        std::cout << "Exception in Proc2" << std::endl;
        std::rethrow_exception(currentException);
    }
}

void proc1(void) {
    try {
        std::cout << "Proc1 called" << std::endl;
        proc2();
    } catch (const std::exception& e) {
        std::cout << "Exception in Proc1:" << e.what() << std::endl;

    }
}

int main(int argc, char** argv) {
    proc1();
    return 0;
}

