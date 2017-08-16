/* 
 * File:   TListItem.cpp
 * Author: dvdemon
 * 
 * Created on July 24, 2015, 11:04 AM
 */

#include "TListItem.h"

template <class T> TListItem<T>::TListItem(T* value) {
    _value = std::shared_ptr<T> (value);
    _next = nullptr;
}

template <class T> std::shared_ptr<T> TListItem<T>::GetValue() {
    return _value;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() {
    return _next;
}

template <class T> void TListItem<T>::SetNext(std::shared_ptr<TListItem> next) {
    _next = next;
}

template <class T> void TListItem<T>::PushBack(std::shared_ptr<TListItem> next) {
    if (_next != nullptr) {
        _next->PushBack(next);
    } else {
        _next = next;
    }
}

template <class T> TListItem<T>::~TListItem() {
}

#include "TStack.h"
#include "Triangle.h"
template class TListItem<TStack<Triangle>>;
template class TListItem<Triangle>;
