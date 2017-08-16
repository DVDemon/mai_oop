/* 
 * File:   TStackItem.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:11 PM
 */

#include "TStackItem.h"
#include <iostream>

TStackItem::TStackItem(const std::shared_ptr<Triangle>& triangle) {
    this->triangle = triangle;
    this->next = nullptr;
    std::cout << "Stack item: created" << std::endl;
}


std::shared_ptr<TStackItem> TStackItem::SetNext(std::shared_ptr<TStackItem> &next) {
    std::shared_ptr<TStackItem> old = this->next;
    this->next = next;
    return old;
}

std::shared_ptr<Triangle> TStackItem::GetTriangle() const {
    return this->triangle;
}

std::shared_ptr<TStackItem> TStackItem::GetNext() {
    return this->next;
}

TStackItem::~TStackItem() {
    std::cout << "Stack item: deleted" << std::endl;
    //delete next;

}

std::ostream& operator<<(std::ostream& os, const TStackItem& obj) {
    os << "[" << *obj.triangle << "]" << std::endl;
    return os;
}
