/* 
 * File:   SquareEquation.h
 * Author: dvdemon
 *
 * Created on August 27, 2015, 8:39 AM
 */

#ifndef SQUAREEQUATION_H
#define	SQUAREEQUATION_H

#include <exception>
#include <iostream>
#include <string>

class WrongEquationException : public std::exception {
private:
    std::string msg;
public:

    WrongEquationException(double value) {
        msg = "Wrong determinant:" + std::to_string(value);
    };

    const char * what() const noexcept override {
        return msg.c_str();
    };
    
    virtual ~WrongEquationException(){
        std::cout << "I'm die!" << std::endl;
    }
};

class SquareEquation {
public:
    SquareEquation(double, double, double);
    double FindX1();
    double FindX2();
    virtual ~SquareEquation();
private:
    double a;
    double b;
    double c;
};

#endif	/* SQUAREEQUATION_H */

