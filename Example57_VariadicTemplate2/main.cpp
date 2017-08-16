#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

template <class... Ts> class tuple {
};

template <class T, class... Ts>
class tuple<T, Ts...> : public tuple<Ts...> {
    public:
    tuple(T t, Ts... ts) : tuple<Ts...>(ts...), value(t) {
    }
    tuple<Ts...> &next = static_cast<tuple<Ts...>&>(*this);
    T value;
};

int main(int argc, char** argv) {
    tuple<double, uint64_t, const char*> t1(12.2, 42, "big");
    std::cout << t1.value << std::endl;
    std::cout << t1.next.value << std::endl;
    std::cout << t1.next.next.value << std::endl;
    
    return 0;
}
