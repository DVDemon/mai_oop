/* 
 * File:   Rectangle.h
 * Author: dvdemon
 *
 * Created on August 29, 2015, 4:59 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

class Rectangle {
public:
    Rectangle(int,int);
    int        operator[](int i);
    operator int();
    void       print();
    virtual ~Rectangle();
private:
    int _width,_height;

};

#endif	/* RECTANGLE_H */

