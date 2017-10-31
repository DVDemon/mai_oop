#include <iostream>

// добавляем перегрузку оператора ())
template <class T> class Functor{
    public:        
        Functor<T>& operator()(){
            std::cout << "[functor]" << std::endl;
            return *this;
        }
};

// считаем вызовы конструктора "по умолчанию"
template <class T> class RefCount{

    public:  
        RefCount(){
            static int count = 0;
            count++;
            std::cout << "RefCount:" << count << std::endl;
        }
};

// добавляем классу родителя
template <class T,template <class> class Template> class AddFeature : 
     public T, public Template<T>{
};

// простой класс :-)
class A{};

// void fooo(auto a){} // так нельзя

int main(int argc, char** argv) {

   // AddFeature<A,RefCount> a,a1,a2,a3;
   // AddFeature<A,RefCount> a4;
 
    AddFeature<A,Functor> b;
    b()()()()()();
    

    AddFeature<AddFeature<A,RefCount>,Functor> c;

    
    auto d=c;
    d();

    
    return 0;
}

