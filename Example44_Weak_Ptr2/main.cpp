#include <iostream>
#include <cstdlib>
#include <memory>

class A {
private:
    const char* name;
public:

    A(const char*value) : name(value) {
    };

    void Print() {
        std::cout << name << std::endl;
    }
    virtual ~A(){
        std::cout << "I'm die: "<< name << std::endl;
    }
};

class WeakPrint {
private:
    std::weak_ptr<A> array[5];
public:

    WeakPrint(std::shared_ptr<A> value[5]) {
        for (int i = 0; i < 5; i++)
            array[i] = value[i];
    }

    void Print() {
        for (int i = 0; i < 5; i++)
            if (std::shared_ptr<A> a = array[i].lock())
                a->Print();

    }

};

int main(int argc, char** argv) {
    std::shared_ptr<A> array[5] = {
        std::shared_ptr<A>(new A("1")),
        std::shared_ptr<A>(new A("2")),
        std::shared_ptr<A>(new A("3")),
        std::shared_ptr<A>(new A("4")),
        std::shared_ptr<A>(new A("5"))};


    WeakPrint printer(array);

    printer.Print();

    std::cout << std::endl << "Kill the second!!" << std::endl;
    array[2].reset();

    printer.Print();

    return 0;
}

