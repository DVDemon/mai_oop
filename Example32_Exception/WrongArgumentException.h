/* 
 * File:   WrongArgumentException.h
 * Author: dvdemon
 *
 * Created on September 20, 2015, 2:05 PM
 */

#ifndef WRONGARGUMENTEXCEPTION_H
#define	WRONGARGUMENTEXCEPTION_H

#include <exception>

class WrongArgumentException : public std::exception {
public:

    virtual const char* what() {
        //throw int(1);
        return "Wrong argument exception";
    }
};

#endif	/* WRONGARGUMENTEXCEPTION_H */

