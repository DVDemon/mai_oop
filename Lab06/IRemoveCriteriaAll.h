/* 
 * File:   IRemoveCriteriaAll.h
 * Author: dvdemon
 *
 * Created on August 12, 2015, 11:41 AM
 */

#ifndef IREMOVECRITERIAALL_H
#define	IREMOVECRITERIAALL_H

#include "IRemoveCriteria.h"

template <class T> class IRemoveCriteriaAll : public IRemoveCriteria<T>{
public:
    IRemoveCriteriaAll() {};
    bool isIt(T* value) override{
        return true;
    }
private:

};

#endif	/* IREMOVECRITERIAALL_H */

