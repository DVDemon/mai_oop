/* 
 * File:   SquareEquation.h
 * Author: dvdemon
 *
 * Created on August 27, 2015, 8:39 AM
 */

#ifndef SQUAREEQUATION_H
#define	SQUAREEQUATION_H

class SquareEquation {
public:
	SquareEquation(double,double,double);
	double FindX1();
	double FindX2();
private:
    	double a;
	double b;
	double c;
};

#endif	/* SQUAREEQUATION_H */

