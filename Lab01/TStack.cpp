/* 
 * File:   TStack.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:10 PM
 */

#include "TStack.h"

TStack::TStack() : head(nullptr) {
}

TStack::TStack(const TStack& orig) {
    head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const TStack& stack) {

    TStackItem *item = stack.head;
    
    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }
    
    return os;
}

void TStack::push(Triangle &&triangle) {
    TStackItem *other = new TStackItem(triangle);
    other->SetNext(head);
    head = other;

}

bool TStack::empty() {
    return head == nullptr;
}

Triangle TStack::pop() {
    Triangle result;
    if (head != nullptr) {
        TStackItem *old_head = head;
        head = head->GetNext();
        result = old_head->GetTriangle();
        old_head->SetNext(nullptr);
        delete old_head;
    }

    return result;
}

TStack::~TStack() {
    delete head;
}

