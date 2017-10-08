/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "ChildItem.h"

int main(int argc, char** argv) {


    ChildItem *pChild = new ChildItem();
    BaseItem *pBase = (BaseItem *) pChild;

    //Item *ptr = pChild;
   // ptr->GetMyName();
    //pChild->foo();

    std::cout << "Child GetMyName:" << pChild->GetMyName() << std::endl;
    std::cout << "Child GetMyOriginalName:" << pChild->GetMyOriginalName() << std::endl;


    std::cout << "Base GetMyName:" << pBase->GetMyName() << std::endl;
    std::cout << "Base GetMyOriginalName:" << pBase->GetMyOriginalName() << std::endl;


    delete pBase;
    return 0;
}

