/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <memory>

#include "Triangle.h"
#include "TStack.h"
#include "TList.h"
#include "IRemoveCriteriaByValue.h"
#include "IRemoveCriteriaAll.h"

int main(int argc, char** argv) {
    TList<TStack<Triangle>,Triangle> list;
    
    list.InsertSubitem(new Triangle(1,1,1));
    list.InsertSubitem(new Triangle(2,1,1));
    list.InsertSubitem(new Triangle(3,1,1));
    list.InsertSubitem(new Triangle(4,1,1));
    list.InsertSubitem(new Triangle(5,1,1));
    list.InsertSubitem(new Triangle(6,1,1));
    list.InsertSubitem(new Triangle(7,1,1));

    std::cout << list << std::endl;
    
    IRemoveCriteriaByValue<Triangle> criteria(Triangle(4,1,1));
    IRemoveCriteriaAll<Triangle> criteriaAll;
    list.RemoveSubitem(&criteria);
    
    
    
    std::cout << list << std::endl;

   return 0;
}
