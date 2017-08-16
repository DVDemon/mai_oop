/* 
 * File:   TStackItem.h
 * Author: dvdemon
 *
 * Created on July 18, 2015, 7:11 PM
 */

#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

#include "Triangle.h"
class TStackItem {
public:
    TStackItem(const Triangle& triangle);
    TStackItem(const TStackItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TStackItem& obj);
    
    TStackItem* SetNext(TStackItem* next);
    TStackItem* GetNext();
    Triangle GetTriangle() const;

    virtual ~TStackItem();
private:
    Triangle triangle;
    TStackItem *next;
};

#endif	/* TSTACKITEM_H */

