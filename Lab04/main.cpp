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
#include "TStackItem.h"
#include "TStack.h"





// template stack on shared_ptr with iterator
int main(int argc, char** argv) {
    
    TStack<Triangle> stack;
    
    stack.push(std::shared_ptr<Triangle>(new Triangle(1,1,1)));
    stack.push(std::shared_ptr<Triangle>(new Triangle(2,2,2)));
    stack.push(std::shared_ptr<Triangle>(new Triangle(3,3,3)));
    
    for(auto i : stack)  std::cout << *i << std::endl;
    
    return 0;
}
