#include <iostream>

// class template:

template <class T> class MyContainer {
    T element;
public:

    MyContainer(T arg) {
        element = arg;
    }

    T increase() {
        return ++element;
    }

    T decrease() {
        return --element;
    }
};

// class template specialization:
template <> class MyContainer <char> {
    char element;
public:

    MyContainer(char arg) {
        element = arg;
    }

    char uppercase() {
        if ((element >= 'a') && (element <= 'z'))
            element += 'A' - 'a';
        return element;
    }

    char increase() {
        element += 'A' - 'a';
        return element;
    }

    char decrease() {
        element -= 'A' - 'a';
        return element;
    }
};

int main(int argc, char** argv) {
    MyContainer<int> myint(7);
    MyContainer<char> mychar('j');
    std::cout << myint.increase() << std::endl;
    std::cout << mychar.uppercase() << std::endl;
    std::cout << mychar.decrease() << std::endl;
    std::cout << mychar.increase() << std::endl;
    return 0;
}

