#include <iostream>
#include <string>
#include <memory>

template <class T> T&& move(T& value) {
    return static_cast<T&&> (value);
}

class Resource {
protected:
    std::shared_ptr<std::string> _name;
public:

    Resource() : _name(new std::string()) {
        //std::cout << "Resource: default constructor " << std::endl;
    }

    Resource(const char* name) : _name(new std::string(name)) {
        //std::cout << "Resource: create constructor " << name << std::endl;
    }

    Resource(const Resource &other) {
        std::string *pointer = new std::string();
        *pointer = *other._name.get();
        _name.reset(pointer);
        //std::cout << "Resource: copy constructor " << *_name.get() << std::endl;
    }

    Resource(const Resource &&other) {
        _name = other._name;
       // std::cout << "Resource: move constructor " << *_name.get() << std::endl;
    }

    Resource & operator=(const Resource& other) {
        *_name.get() = *other._name.get();
        //std::cout << "Resource: copy operator " << *_name.get() << std::endl;
        return *this;
    }

    Resource & operator=(const Resource&& other) {
        _name = other._name;
       // std::cout << "Resource: move operator " << *_name.get() << std::endl;
        return *this;
    }

    void print() {
        std::cout << "Resource: " << *_name.get() << std::endl;
    }
};

class A {
protected:
    Resource _resource;
public:

    A(Resource &&r) : _resource(r) {
    };

    A(A &other) : _resource(other._resource) {
    };

    A(A &&other) : _resource((const Resource&&)other._resource) {
    };

    A& operator=(const A& other) {
        _resource = other._resource;
        return *this;
    }

    A& operator=(const A&& other) {
        _resource = (const Resource&&)other._resource;
        return *this;
    }

    void print() {
        _resource.print();
    }
};

void swap1(A & left, A& right) {
    A tmp = right;
    right = left;
    left = tmp;
}

void swap2(A & left, A& right) {
    A tmp(move<A>(right));
    right = move<A>(left);
    left = move<A>(tmp);
}

int main(int argc, char** argv) {


    A a1(Resource("002198372198371298371928379812739812379812739837123987198237219837981723917893712983728917398127391837"));
    A a2(Resource("a238н293н9832у9823н2398к8394н9283г92г39213912321312213123123123213212"));

    std::cout << std::endl << "Swap copy" << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();
    for (uint64_t i = 0; i < 10000000; i++) swap1(a1, a2);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>(end - begin).count() << std::endl;


    std::cout << std::endl << "Swap move" << std::endl;
    begin = std::chrono::high_resolution_clock::now();
    for (uint64_t i = 0; i < 10000000; i++) swap2(a1, a2);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>(end - begin).count() << std::endl;

    return 0;
}

