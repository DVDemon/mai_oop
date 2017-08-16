/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on August 15, 2015, 2:48 PM
 */

#include <cstdlib>

using namespace std;

#include "Triangle.h"
#include "TStack.h"
#include <future>
#include <functional>
#include <random>
#include <thread>

int main(int argc, char** argv) {

    TStack<Triangle> stack_triangle;
    typedef std::function<void (void) > command;
    TStack < command> stack_cmd;


    command cmd_insert = [&]() {
        std::cout << "Command: Create triangles" << std::endl;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 1000);

        for (int i = 0; i < 10; i++) {
            int side = distribution(generator);
            stack_triangle.push(new Triangle(side, side, side));
        }
    };

    command cmd_print = [&]() {
        std::cout << "Command: Print stack" << std::endl;
        std::cout << stack_triangle;
    };


    command cmd_reverse = [&]() {
        std::cout << "Command: Reverse stack" << std::endl;
        
        TStack<Triangle> stack_tmp;
        while(!stack_triangle.empty()) stack_tmp.push(stack_triangle.pop_last());
        while(!stack_tmp.empty()) stack_triangle.push(stack_tmp.pop());
        
        
    };

    stack_cmd.push(std::shared_ptr<command> (&cmd_print, [](command*) {
    })); // using custom deleter
    stack_cmd.push(std::shared_ptr<command> (&cmd_reverse, [](command*) {
    })); // using custom deleter
    stack_cmd.push(std::shared_ptr<command> (&cmd_print, [](command*) {
    })); // using custom deleter
    stack_cmd.push(std::shared_ptr<command> (&cmd_insert, [](command*) {
    })); // using custom deleter


    while (!stack_cmd.empty()) {
        std::shared_ptr<command> cmd = stack_cmd.pop();
        std::future<void> ft = std::async(*cmd);      
        ft.get();
        //std::thread(*cmd).detach();
    }
    

    return 0;
}

