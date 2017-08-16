/* 
 * File:   TStackItem.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:11 PM
 */

#include "TStackItem.h"
#include <iostream>

template <class T> TStackItem<T>::TStackItem(T* item) {
    this->item = std::shared_ptr<T>(item);
    this->next = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

template <class T> TStackItem<T>::TStackItem(std::shared_ptr<T> item) {
    this->item = item;
    this->next = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

template <class T> std::shared_ptr<TStackItem<T>> TStackItem<T>::SetNext(std::shared_ptr<TStackItem<T>> next) {
    std::shared_ptr<TStackItem < T>> old = this->next;
    this->next = next;
    return old;
}

template <class T> std::shared_ptr<T> TStackItem<T>::GetValue() const {
    return this->item;
}

template <class T> std::shared_ptr<TStackItem<T>> TStackItem<T>::GetNext() {
    return this->next;
}

template <class T> TStackItem<T>::~TStackItem() {
    //std::cout << "Stack item: deleted" << std::endl;

}

template <class A> std::ostream& operator<<(std::ostream& os, const TStackItem<A>& obj) {
    os << "[" << *obj.item << "]" << std::endl;
    return os;
}


#include "Triangle.h"
template class TStackItem<Triangle>;
template std::ostream& operator<<(std::ostream& os, const TStackItem<Triangle>& obj);
