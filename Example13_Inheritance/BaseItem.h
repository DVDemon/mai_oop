/* 
 * File:   BaseItem.h
 * Author: dvdemon
 *
 * Created on August 28, 2015, 9:11 AM
 */

#ifndef BASEITEM_H
#define	BASEITEM_H

#include "Item.h"
class BaseItem : public Item {
public:
    BaseItem();
    const char * GetMyName() override;
    const char * GetMyOriginalName();
    virtual ~BaseItem();
private:

};

#endif	/* BASEITEM_H */

