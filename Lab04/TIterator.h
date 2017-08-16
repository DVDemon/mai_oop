/* 
 * File:   TIterator.h
 * Author: dvdemon
 *
 * Created on July 24, 2015, 11:24 AM
 */

#ifndef TITERATOR_H
#define	TITERATOR_H
#include <memory>
#include <iostream>

template <class node, class T>
class TIterator
{
public:

    TIterator(std::shared_ptr<node> n)   {
        
        node_ptr = n;
    }

    std::shared_ptr<T> operator * (){
        return node_ptr->GetValue();
    }

    std::shared_ptr<T> operator -> (){
        return node_ptr->GetValue();
    }

    void operator ++ (){
        node_ptr = node_ptr->GetNext();
    }

    TIterator operator ++ (int){
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIterator const& i){
        return node_ptr == i.node_ptr;
    }

    bool operator != (TIterator const& i){
        return !(*this == i);
    }

private:

    std::shared_ptr<node> node_ptr;
};

#endif	/* TITERATOR_H */

