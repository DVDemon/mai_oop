/* 
 * File:   TStack.h
 * Author: dvdemon
 *
 * Created on July 18, 2015, 7:10 PM
 */

#ifndef TSTACK_H
#define	TSTACK_H

#include "TIterator.h"
#include "TStackItem.h"
#include <memory>
#include <future>
#include <mutex>

template <class T> class TStack {
public:
    TStack();
    
    void push(T* item);
    void push(std::shared_ptr<T> item);
    bool empty();
    size_t size();
    
    TIterator<TStackItem<T>,T> begin();
    TIterator<TStackItem<T>,T> end();
    
    std::shared_ptr<T> operator[] (size_t i);
    void sort();
    void sort_parallel();
    
    std::shared_ptr<T> pop();
    std::shared_ptr<T> pop_last();
    template <class A> friend std::ostream& operator<<(std::ostream& os,const TStack<A>& stack);
    virtual ~TStack();
private:
    std::future<void> sort_in_background(); 
    std::shared_ptr<TStackItem<T>> head;
    
};

#endif	/* TSTACK_H */

