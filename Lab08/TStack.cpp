/* 
 * File:   TStack.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:10 PM
 */

#include "TStack.h"
#include <exception>

template <class T> TStack<T>::TStack() : head(nullptr) {
    //std::cout << "Stack created" << std::endl;
}


template <class T> std::shared_ptr<T> TStack<T>::operator[](size_t i) {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    if (i > size() - 1) throw std::invalid_argument("index greater then stack size");
    size_t j = 0;

    for (std::shared_ptr<T> a : * this) {
        if (j == i) return a;
        j++;
    }

    return std::shared_ptr<T>(nullptr);
}

template <class T> std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
    for(auto i:stack) os << *i << std::endl;
    return os;
}

template <class T> void TStack<T>::push(T *item) {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    std::shared_ptr<TStackItem < T >> other(new TStackItem<T>(item,&stack_mutex));
    other->SetNext(head);
    head = other;

}

template <class T> void TStack<T>::push(std::shared_ptr<T> item) {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    std::shared_ptr<TStackItem < T >> other(new TStackItem<T>(item,&stack_mutex));
    other->SetNext(head);
    head = other;

}

template <class T> bool TStack<T>::empty() {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    return head == nullptr;
}

template <class T> std::shared_ptr<T> TStack<T>::pop() {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetValue();
        head = head->GetNext();
    }

    return result;
}

template <class T> std::shared_ptr<T> TStack<T>::pop_last() {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    std::shared_ptr<T> result;

    if (head != nullptr) {
        std::shared_ptr<TStackItem < T>> element = head;
        std::shared_ptr<TStackItem < T>> prev = nullptr;

        while (element->GetNext() != nullptr) {
            prev = element;
            element = element->GetNext();
        }

        if (prev != nullptr) {
            prev->SetNext(nullptr);
            result = element->GetValue();

        } else {
            result = element->GetValue();
            head = nullptr;
        }
    }

    return result;

}

template <class T> size_t TStack<T>::size() {
    std::lock_guard<std::recursive_mutex> lock(stack_mutex);
    int result = 0;
    for (auto i : * this) result++;
    return result;
}

template <class T> TIterator<TStackItem<T>, T> TStack<T>::begin() const{
    return TIterator<TStackItem<T>, T>(head);
}

template <class T> TIterator<TStackItem<T>, T> TStack<T>::end() const{
    return TIterator<TStackItem<T>, T>(nullptr);
}

template <class T> TStack<T>::~TStack() {
    //std::cout << "Stack deleted" << std::endl;
}

#include "Triangle.h"

#include <functional>
template class TStack<Triangle>;
template class TStack<std::function<void(void)>>;
template std::ostream& operator<<(std::ostream& os, const TStack<Triangle>& stack); 