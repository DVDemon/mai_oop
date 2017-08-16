/* 
 * File:   TStackItem.h
 * Author: dvdemon
 *
 * Created on July 18, 2015, 7:11 PM
 */

#ifndef TSTACKITEM_H
#define	TSTACKITEM_H
#include <memory>
#include <thread>
#include <mutex>

template<class T> class TStackItem {
public:
    TStackItem(T *item,std::recursive_mutex                     *parent);
    TStackItem(std::shared_ptr<T> item,std::recursive_mutex                     *parent);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const TStackItem<A>& obj);
    
    std::shared_ptr<TStackItem<T>> SetNext(std::shared_ptr<TStackItem> next);
    std::shared_ptr<TStackItem<T>> GetNext();
    std::shared_ptr<T> GetValue() const;
    
    virtual ~TStackItem();
private:
    std::shared_ptr<T> item;
    std::shared_ptr<TStackItem<T>> next;
    std::recursive_mutex                     *stack_mutex;

};

#endif	/* TSTACKITEM_H */

