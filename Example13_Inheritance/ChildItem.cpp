/* 
 * File:   ChildItem.cpp
 * Author: dvdemon
 * 
 * Created on August 28, 2015, 9:11 AM
 */

#include "ChildItem.h"
#include <iostream>

ChildItem::ChildItem() {
}

void ChildItem::foo() {
    std::cout << "Fooo!!!" << std::endl;
}

const char * ChildItem::GetMyName() {
    return "ChildItem";
}

const char * ChildItem::GetMyOriginalName() {
    return "ChildItem";
}

ChildItem::~ChildItem() {
}

