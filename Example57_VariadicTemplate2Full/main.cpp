#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

// сам шаблон
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

// специальная структура для определения типа конкретного элемента в tuple
template <size_t, class> struct elem_type_holder;

// без параметра - это тип базового класса
template <class T, class... Ts> struct elem_type_holder<0, tuple<T, Ts...>> {
  typedef T type;
};

// это тип k-го класса в цепочке наследования
template <size_t k, class T, class... Ts> struct elem_type_holder<k, tuple<T, Ts...>> {
  typedef  typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};

// шаблон функции get для получения параметра (данная специализация работает только при index==0)
template <size_t index,class ...Ts>
typename std::enable_if<index == 0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
get(tuple<Ts...>& t){
    return t.value;
}

// шаблон функции get для получения параметра (данная специализация работает только при index!=0)
template <size_t index,class T,class ...Ts>
typename std::enable_if<index != 0, typename elem_type_holder<index, tuple<T,Ts...>>::type&>::type
get(tuple<T,Ts...>& t){
    tuple<Ts...> &base = t;
    return get<index-1>(base);
}

int main(int argc, char** argv) {
    tuple<double, uint64_t, const char*> t1(100.1, 1828, "some string");
    std::cout << t1.value << std::endl;
    std::cout << t1.next.value << std::endl;
    std::cout << t1.next.next.value << std::endl;

    std::cout << "0th elem is " << get<0>(t1) << std::endl;
    std::cout << "1th elem is " << get<1>(t1) << std::endl;
    std::cout << "2th elem is " << get<2>(t1) << std::endl;
    //std::cout << "3th elem is " << get<3>(t1) << std::endl;

    return 0;
}
