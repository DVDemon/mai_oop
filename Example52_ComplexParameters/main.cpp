#include <iostream>
#include <exception>
#include <string>

class BadIndexException : public std::exception {
private:
    std::string msg;
public:

    BadIndexException(int index, int size) {
        msg = "Index:" + std::to_string(index) + " is out of bound for array[0.." + std::to_string(size-1) + "]";
    }

    const char* what() const noexcept override {
        return msg.c_str();
    }

};

template <class TYPE, TYPE def_value, size_t SIZE = 10 > class Array {
protected:
    TYPE _array[SIZE];
public:

    Array() {
        for (int i = 0; i < SIZE; i++) {
            _array[i] = def_value;
        }
    }

    const size_t size() {
        return SIZE;
    }

    const TYPE operator[](size_t index) {
        if ((index >= 0) && (index < SIZE)) return _array[index];
        else throw BadIndexException(index, SIZE);
    }
};

int main(int argc, char** argv) {

    try {
        Array<int, 0, 5> array;
        for (int i = 0; i < array.size(); i++) {
            std::cout << "Value=" << array[i] << std::endl;
        }
    } catch (const std::exception &ex) {
        std::cout << "Exception in runtime" << std::endl << ex.what() << std::endl;
    }

    return 0;
}

