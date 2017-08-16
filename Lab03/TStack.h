/* 
 * File:   TStack.h
 * Author: dvdemon
 *
 * Created on July 18, 2015, 7:10 PM
 */

#ifndef TSTACK_H
#define	TSTACK_H

#include "Triangle.h"
#include "TStackItem.h"
#include <memory>

template <class T> class TStack {
public:
    TStack();
    
    void push(std::shared_ptr<T> &&item);
    bool empty();
    std::shared_ptr<T> pop();
    template <class A> friend std::ostream& operator<<(std::ostream& os,const TStack<A>& stack);
    virtual ~TStack();
private:
    
    std::shared_ptr<TStackItem<T>> head;
};

#endif	/* TSTACK_H */

