/* 
 * File:   tuple.h
 * Author: dvdemon
 *
 * Created on October 17, 2015, 7:43 PM
 */

#ifndef TUPLE_H
#define	TUPLE_H

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
  typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
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

#endif	/* TUPLE_H */

