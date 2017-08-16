/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>

using namespace std;

class A {
public:

    explicit A(int value) : _value(value) {
    };
private:
    int _value;
};

void Foo(A a) {
};

int main(int argc, char** argv) {

    A a1(1);
    A a2 = 2;
    Foo(3);

    return 0;
}

