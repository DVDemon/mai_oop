/* 
 * File:   TStackItem.cpp
 * Author: dvdemon
 * 
 * Created on July 18, 2015, 7:11 PM
 */

#include "TStackItem.h"
#include <iostream>

TStackItem::TStackItem(const Triangle& triangle) {
    this->triangle = triangle;
    this->next = nullptr;
    std::cout << "Stack item: created" << std::endl;
}

TStackItem::TStackItem(const TStackItem& orig) {
    this->triangle = orig.triangle;
    this->next = orig.next;
    std::cout << "Stack item: copied" << std::endl;
}

TStackItem* TStackItem::SetNext(TStackItem* next) {
    TStackItem* old = this->next;
    this->next = next;
    return old;
}

Triangle TStackItem::GetTriangle() const {
    return this->triangle;
}

TStackItem* TStackItem::GetNext() {
    return this->next;
}

TStackItem::~TStackItem() {
    std::cout << "Stack item: deleted" << std::endl;
    delete next;

}

std::ostream& operator<<(std::ostream& os, const TStackItem& obj) {
    os << "[" << obj.triangle << "]" << std::endl;
    return os;
}
