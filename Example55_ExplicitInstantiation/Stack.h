/* 
 * File:   Stack.h
 * Author: dvdemon
 *
 * Created on October 11, 2015, 12:49 PM
 */

#ifndef STACK_H
#define	STACK_H

template <class T,void (*func)(T&)> class MyStack {
private:

    class StackItem {
    public:
        StackItem *next;
        T  item;
        StackItem(T value) : item(value), next(nullptr){};
    };

    StackItem* _current;
    int _size;



public:
    MyStack(void);
    void Push(T item);
    T Pop(void);
    ~MyStack(void);
};

#endif	/* STACK_H */

