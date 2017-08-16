/* 
 * File:   TStack.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:10 PM
 */

#include "TStack.h"

TStack::TStack() : head(nullptr) {
}


std::ostream& operator<<(std::ostream& os, const TStack& stack) {

    std::shared_ptr<TStackItem> item = stack.head;
    
    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }
    
    return os;
}

void TStack::push(std::shared_ptr<Triangle> &&triangle) {
    std::shared_ptr<TStackItem> other(new TStackItem(triangle));
    other->SetNext(head);
    head = other;

}

bool TStack::empty() {
    return head == nullptr;
}

std::shared_ptr<Triangle> TStack::pop() {
    std::shared_ptr<Triangle> result;
    if (head != nullptr) {
        result = head->GetTriangle();
        head = head->GetNext();
    }

    return result;
}

TStack::~TStack() {

}

