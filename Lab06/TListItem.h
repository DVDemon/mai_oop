/* 
 * File:   TListItem.h
 * Author: dvdemon
 *
 * Created on July 24, 2015, 11:04 AM
 */

#ifndef TLISTITEM_H
#define	TLISTITEM_H
#include <memory>

template <class T> class TListItem {
public:
    TListItem(T* value);
    
    std::shared_ptr<T> GetValue();
    std::shared_ptr<TListItem<T>> GetNext();
    void SetNext(std::shared_ptr<TListItem<T>> next);
    void PushBack(std::shared_ptr<TListItem<T>> next);
    
    virtual ~TListItem();
private:
    std::shared_ptr<T> _value;
    std::shared_ptr<TListItem> _next;

};

#endif	/* TLISTITEM_H */

