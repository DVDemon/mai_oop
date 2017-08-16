#include <iostream>

// два параметра, через запятую
template <class A, class B> class Sum {
private:
    A a;
    B b;
public:

    Sum(A a_value, B b_value) : a(a_value), b(b_value) {
    }
    
    // параметры C и D (а не A,B) поскольку это ссылка на другой шаблон, описаный ниже
    template <class C,class D>  friend std::ostream& operator<<(std::ostream & os, Sum<C,D> &sum);
};

// шаблон функции у которой в качестве параметра шаблон
template <class A, class B> std::ostream& operator<<(std::ostream & os, Sum<A, B> &sum) {
    os << sum.a << "," << sum.b << " ";
    return os;
};

int main(int argc, char** argv) {

    Sum<int,int> sum(1,2);
    std::cout << sum << std::endl;
    
    // передаем в качестве одного из параметров тип, сконструированный по шаблону
    Sum<int,Sum<int,int>> 
            sum_of_sum(1,Sum<int,int>(2,3));
    std::cout << sum_of_sum;
    
    return 0;
}

