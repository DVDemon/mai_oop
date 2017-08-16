/* 
 * File:   ChildItem.h
 * Author: dvdemon
 *
 * Created on August 28, 2015, 9:11 AM
 */

#ifndef CHILDITEM_H
#define	CHILDITEM_H
#include "BaseItem.h"

class ChildItem : public BaseItem{
public:
    ChildItem();
    const char * GetMyName();
    const char * GetMyOriginalName();
    void foo();
    virtual ~ChildItem();
private:

};

#endif	/* CHILDITEM_H */

