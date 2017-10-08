/* 
 * File:   Rectangle.h
 * Author: dvdemon
 *
 * Created on August 29, 2015, 4:59 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include <iostream>

class Rectangle {
public:
    Rectangle(int,int);
    Rectangle& operator++();
    Rectangle& operator++(int);
    int        operator[](int i);
    operator int();

    friend std::ostream& operator <<(std::ostream &os,const Rectangle &rec);
    //friend std::ostream& operator <<(std::ostream &os,const Rectangle &&rec);
    //friend Rectangle     operator +(const Rectangle &left, const Rectangle &right);
    
    virtual ~Rectangle();
private:
    int _width,_height;

};

#endif	/* RECTANGLE_H */

