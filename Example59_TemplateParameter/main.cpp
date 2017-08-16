#include <iostream>
#include <string>

template <class T> class Payload {
private:
    T value;
public:

    Payload(T &&val) : value(val) {
    };

    T& GetValue() {
        return value;
    };
};

template <class T> class Payload2 {
private:
    T value;
public:

    Payload2(T val) : value(val) {
    };

    T GetValue() {
        return -value;
    };
};

template <template <class A> class PL, // шаблон-параметр
                             class T> class Printer {
private:
    PL<T> value; // класс, полученый применением шаблона
public:

    Printer(PL<T> val) : value(val) {
        std::cout << value.GetValue() << std::endl;
    }
};

int main(int argc, char** argv) {

    Printer<Payload, int> printer1(Payload<int>(10));
    Printer<Payload, const char*> printer2(Payload<const char*>((const char*) "Hello world!"));
    Printer<Payload2, int> printer3(Payload2<int>(10));
    return 0;
}

