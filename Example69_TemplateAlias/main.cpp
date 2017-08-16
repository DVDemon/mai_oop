#include <iostream>

template <class A,class B> class Pair {
    public:
        A a;
        B b;
        Pair(A v1,B v2) : a(v1), b(v2) {
        std::cout << a << "," << b << std::endl;
        };
};

template <class A> using SamePair =  Pair<A,A>;

int main(int argc, char** argv) {

    Pair<int,const char*> a(1,"one");
    SamePair<int> b(2,2);
    
    return 0;
}

