/* 
 * File:   TStack.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:10 PM
 */

#include "TStack.h"

template <class T> TStack<T>::TStack() : head(nullptr) {
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

template <class T> void TStack<T>::push(std::shared_ptr<T> &&item) {
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
        result = head->GetTriangle();
        head = head->GetNext();
    }

    return result;
}

template <class T> TStack<T>::~TStack() {

}

#include "Triangle.h"
template class TStack<Triangle>;
template std::ostream& operator<<(std::ostream& os, const TStack<Triangle>& stack); 