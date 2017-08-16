#include "Stack.h"

template <class T,void (*func)(T&)> MyStack<T,func>::MyStack(void) {
    _size = 0;
    _current = nullptr;
}

template <class T,void (*func)(T&)> void MyStack<T,func>::Push(T item) {
    _size++;

    StackItem *stack_item = new StackItem(item);
    stack_item->next = _current;
    stack_item->item = item;
    _current = stack_item;
}

template <class T,void (*func)(T&)> T MyStack<T,func>::Pop(void) {
    T  result = nullptr;
    if (_current != nullptr) {
        StackItem *stack_item = _current;
        result = stack_item->item;
        _current = stack_item->next;
        delete stack_item;
        _size--;
    }

    return result;
}

template <class T,void (*func)(T&)> MyStack<T,func>::~MyStack(void) {
    while (_current != nullptr) {
        StackItem *old = _current;
        _current = _current->next;

        T ptr =old->item;
        delete ptr;
//        func(old->item);
        delete old;
    }
}


#include "MyClass.h"
//void deleterMyClass(MyClass&){}
void deleterMyClassPtr(MyClass*& ptr) {delete ptr;}
//template class MyStack<class MyClass,&deleterMyClass>;
template class MyStack<class MyClass*,&deleterMyClassPtr>;