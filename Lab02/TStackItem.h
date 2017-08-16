/* 
 * File:   TStackItem.h
 * Author: dvdemon
 *
 * Created on July 18, 2015, 7:11 PM
 */

#ifndef TSTACKITEM_H
#define	TSTACKITEM_H
#include <memory>
#include "Triangle.h"
class TStackItem {
public:
    TStackItem(const std::shared_ptr<Triangle>& triangle);
    friend std::ostream& operator<<(std::ostream& os, const TStackItem& obj);
    
    std::shared_ptr<TStackItem> SetNext(std::shared_ptr<TStackItem> &next);
    std::shared_ptr<TStackItem> GetNext();
    std::shared_ptr<Triangle> GetTriangle() const;

    virtual ~TStackItem();
private:
    std::shared_ptr<Triangle> triangle;
    std::shared_ptr<TStackItem> next;
};

#endif	/* TSTACKITEM_H */

