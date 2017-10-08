/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class A {
public:

    A(const char* value) : next(nullptr), name(value) {
    };

    A(std::ifstream &is) {
        bool is_next;
        is >> name;
        is >> is_next;
        if (is_next) next = new A(is);
    }

    void Serialize(std::ofstream &os) {
        os << name << std::endl;

        if (next != nullptr) {
            os << true;
            next->Serialize(os);
        } else os << false;

    }

    void print() {
        std::cout << "My name:" << name << std::endl;
        if (next) next->print();
    }

    void SetNext(A* value) {
        next = value;
    }

    virtual ~A() {
        delete next;
    }
private:
    std::string name;
    A* next;
};

int main(int argc, char** argv) {

    A * src = new A("First");
    A * second = new A("Second");
    A * last = new A("Last");

    src->SetNext(second);
    second->SetNext(last);

    std::ofstream out_file("buffer.txt", std::ofstream::out);

    src->Serialize(out_file);
    out_file.close();
    delete src;

    std::cout << "Press any key" << std::endl;
    std::cin.get();

    std::ifstream in_file("buffer.txt");
    A* dst = new A(in_file);
    in_file.close();

    dst->print();
    delete dst;

    return 0;
}

