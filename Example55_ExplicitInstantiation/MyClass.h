/* 
 * File:   MyClass.h
 * Author: dvdemon
 *
 * Created on October 11, 2015, 12:50 PM
 */

#ifndef MYCLASS_H
#define	MYCLASS_H

#include <iostream>
class MyClass {
private:
    const char *value;
public:

    MyClass(const char* v) : value(v) {
    };

    void print() {
        std::cout << value << std::endl;
    }

    ~MyClass() {
        std::cout <<"Deleted:" << value << std::endl;
    };
};

void deleterMyClass(MyClass&);
void deleterMyClassPtr(MyClass*&) ;
#endif	/* MYCLASS_H */

