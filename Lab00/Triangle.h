/* 
 * File:   Triangle.h
 * Author: dvdemon
 *
 * Created on July 18, 2015, 7:01 PM
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Triangle : public Figure{
public:
    Triangle();
    Triangle(std::istream &is);
    Triangle(size_t i,size_t j,size_t k);
    Triangle(const Triangle& orig);

    double Square() override;
    void   Print() override;

    virtual ~Triangle();
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};

#endif	/* TRIANGLE_H */

