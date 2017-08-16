/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>

#include <iostream>

void foo(int* p) { std::cout << "nullptr" << std::endl; };
void foo(int a) { std::cout << "0?" << std::endl; };

int main(int argc, char** argv) {
	int* p1 = 0;
	int* p2 = nullptr;
	void *p3 = nullptr;

	if (p1 == p2) std::cout << "1:Equal!" << std::endl;
	if (p3 == p2) std::cout << "2:Equal!" << std::endl;

        delete p3; // errror? no way!
        
	foo(p1);
        foo(p2);

    return 0;
}

