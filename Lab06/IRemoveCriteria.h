/* 
 * File:   IRemoveCriteria.h
 * Author: dvdemon
 *
 * Created on August 12, 2015, 9:24 AM
 */

#ifndef IREMOVECRITERIA_H
#define	IREMOVECRITERIA_H

template <class T> class IRemoveCriteria {
public:
    virtual bool isIt(T* value) = 0;
private:

};

#endif	/* IREMOVECRITERIA_H */

