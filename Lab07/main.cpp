/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on August 12, 2015, 11:46 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


#include "Triangle.h"
#include "TStack.h"
#include <random>
#include <chrono>

int main(int argc, char** argv) {

    TStack<Triangle> stack;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < 10000; i++) {
        int side = distribution(generator);
        stack.push(new Triangle(side, side, side));
    }

    
    std::cout << "Sort -------------" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    //stack.sort();
    stack.sort_parallel();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Done -------------" << std::endl;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;

    //std::cout << stack;


    return 0;
}

