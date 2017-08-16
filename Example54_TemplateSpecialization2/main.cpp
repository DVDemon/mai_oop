#include <iostream>
#include <string>

/*
template <class A,class B,class C> C sum(A a,B b){
    return a+b;
}

template <class A,class B> const char* sum<A,B,const char*>(A a,B b){
    std::string msg= std::to_string(a) + std::to_string(b);
    return msg.c_str();
}
 */
template <class A, class B, class C> class Sum {
private:
    A a;
    B b;
public:

    Sum(A aa, B bb) : a(aa), b(bb) {
    };

    C operator()() {
        return a + b;
    };
};

template <class A, class B> class Sum<A, B, const char*> {
private:
    A a;
    B b;
    std::string msg;
public:

    Sum(A aa, B bb) : a(aa), b(bb) {
    };

    const char* operator()() {
        msg = "Sum="+std::to_string(a) + std::to_string(b);
        return msg.c_str();
    };
};

int main(int argc, char** argv) {

    // std::cout << sum<int,int,int>(5,6) << std::endl;
    //std::cout << sum<int,int,const char*>(5,6) << std::endl;
    std::cout << Sum<int, int, int> (5, 6)() << std::endl;
    std::cout << Sum<int, int, const char*> (5, 6)() << std::endl;
    return 0;
}

