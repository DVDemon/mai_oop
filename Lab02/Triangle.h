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

class Triangle {
public:
    Triangle();
    Triangle(size_t i,size_t j,size_t k);
    Triangle(const Triangle& orig);

    friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);


    Triangle& operator=(const Triangle& right);

    virtual ~Triangle();
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};

#endif	/* TRIANGLE_H */

