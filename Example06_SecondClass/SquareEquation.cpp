/* 
 * File:   SquareEquation.cpp
 * Author: dvdemon
 * 
 * Created on August 27, 2015, 8:39 AM
 */

#include "SquareEquation.h"
#include <math.h>


SquareEquation::SquareEquation(double a,double b ,double cc)
{
	 this->a=a;
	 SquareEquation::b=b;
	 c =cc;
}

double SquareEquation::FindX1()
{
	return (-b-sqrt(b*b-4*a*c))/(2*a);
};

double SquareEquation::FindX2()
{
	return (-b+sqrt(b*b-4*a*c))/(2*a);
};
