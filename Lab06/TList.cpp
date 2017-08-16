/* 
 * File:   TList.cpp
 * Author: dvdemon
 * 
 * Created on July 24, 2015, 11:04 AM
 */

#include "TList.h"

template <class T, class TT> TList<T, TT>::TList() {
    head = nullptr;
}

template <class T, class TT> void TList<T, TT>::RemoveSubitem(IRemoveCriteria<TT> * criteria) {
    std::cout << "---------------------->" << std::endl;
    for (auto i : * this) {
        T copy;
        while (!i->empty()) {
            std::shared_ptr<TT> value = i->pop();

            if (criteria->isIt(&*value))
                std::cout << "List: Delete element " << *value << std::endl;
            else {
                copy.push(new TT(*value));
            }
        }

        while (!copy.empty()) i->push(new TT(*copy.pop()));

    }
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

template <class T, class TT> void TList<T, TT>::InsertSubitem(TT* value) {

    bool inserted = false;
    if (head != nullptr) {

        for (auto i : * this) {
            if (i->size() < 5) {
                i->push(value);
                std::cout << "List: Add Element in list:" << i->size() << std::endl;
                inserted = true;
            }
        }
    }

    if (!inserted) {
        std::cout << "List: New list element created" << std::endl;
        T* t_value = new T();
        t_value->push(value);
        PushBack(t_value);
    }
}

template <class T, class TT> void TList<T, TT>::PushBack(T* value) {
    std::shared_ptr<TListItem < T >> value_item(new TListItem<T>(value));
    std::cout << "List: Added to list" << std::endl;
    if (head != nullptr) {
        head->PushBack(value_item);
    } else {
        head = value_item;
    }
}

template <class T, class TT> bool TList<T, TT>::Remove(T* value) {
    std::shared_ptr<TListItem < T>> item = head;
    std::shared_ptr<TListItem < T>> prev_item = nullptr;
    bool result = false;

    while ((item != nullptr)&&(!result)) {
        if (item->GetValue().get() == value) {
            if (prev_item != nullptr) prev_item->SetNext(item->GetNext());
            else head = item->GetNext();
            result = true;
        } else {
            prev_item = item;
            item = item->GetNext();
        }
    }

    return result;
}

template <class T, class TT> size_t TList<T, TT>::Size() {
    size_t result = 0;

    for (auto a : * this) result++;

    return result;
}

template <class T, class TT> TIterator<TListItem<T>, T> TList<T, TT>::begin() const{
    return TIterator<TListItem<T>, T>(head);
}

template <class T, class TT> TIterator<TListItem<T>, T> TList<T, TT>::end() const{
    return TIterator<TListItem<T>, T>(nullptr);
}

template <class T, class TT> TList<T, TT>::~TList() {
    std::cout << "List: deleted" << std::endl;
}

template <class A, class AA> std::ostream& operator<<(std::ostream& os, const TList<A, AA>& list) {
    std::cout << "List:" << std::endl;
    for(auto i:list) std::cout << *i << std::endl;
    return os;
}

#include "TStack.h"
#include "Triangle.h"

template class TList<TStack<Triangle>, Triangle>;
template std::ostream& operator<<(std::ostream &os,const TList<TStack<Triangle>,Triangle> &list);