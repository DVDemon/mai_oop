#include <iostream>
#include <chrono>

// факториал с помощью функций
template <uint64_t value> uint64_t Factorial(){
  return Factorial<value-1>()*value;    
}

template <> uint64_t Factorial<0>(){
  return 1;    
}

// факториал с помощью классов
template<uint64_t n>
class fact{
    public:
   static const uint64_t value = fact<n-1>::value * n;
};
 
template<>
class fact<0>{
   public:
   static const uint64_t value = 1;
};
 
int main(int argc, char** argv) {
    auto begin = std::chrono::high_resolution_clock::now();
    std::cout << Factorial<50>() << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
 
    begin = std::chrono::high_resolution_clock::now();
    std::cout << fact<50>::value << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
 
    begin = std::chrono::high_resolution_clock::now();
    uint64_t value=1;
    for(int i=1;i<=50;i++) value*=i;
    std::cout << value << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
    
    return 0;
}

