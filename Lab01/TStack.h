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

class TStack {
public:
    TStack();
    TStack(const TStack& orig);
    
    void push(Triangle &&triangle);
    bool empty();
    Triangle pop();
    friend std::ostream& operator<<(std::ostream& os,const TStack& stack);
    virtual ~TStack();
private:
    
    TStackItem *head;
};

#endif	/* TSTACK_H */

