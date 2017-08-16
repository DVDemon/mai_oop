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

class TStack {
public:
    TStack();
    
    void push(std::shared_ptr<Triangle> &&triangle);
    bool empty();
    std::shared_ptr<Triangle> pop();
    friend std::ostream& operator<<(std::ostream& os,const TStack& stack);
    virtual ~TStack();
private:
    
    std::shared_ptr<TStackItem> head;
};

#endif	/* TSTACK_H */

