/* 
 * File:   TStack.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:10 PM
 */

#include "TStack.h"

template <class T> TStack<T>::TStack() : head(nullptr) {
    std::cout << "Stack created" << std::endl;
}


template <class T> std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {

    std::shared_ptr<TStackItem<T>> item = stack.head;
    
    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }
    
    return os;
}

template <class T> void TStack<T>::push(T *item) {
    std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
    other->SetNext(head);
    head = other;

}

template <class T> bool TStack<T>::empty() {
    return head == nullptr;
}

template <class T> std::shared_ptr<T> TStack<T>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetValue();
        head = head->GetNext();
    }

    return result;
}

template <class T> size_t TStack<T>::size(){
    
    int result = 0;
    for(auto i : *this) result++;
    return result;
}


template <class T> TIterator<TStackItem<T>,T> TStack<T>::begin()
{
    return TIterator<TStackItem<T>,T>(head);
}

template <class T> TIterator<TStackItem<T>,T> TStack<T>::end()
{
    return TIterator<TStackItem<T>,T>(nullptr);
}

template <class T> TStack<T>::~TStack() {
std::cout << "Stack deleted" << std::endl;
}

#include "Triangle.h"
template class TStack<Triangle>;
template std::ostream& operator<<(std::ostream& os, const TStack<Triangle>& stack); 