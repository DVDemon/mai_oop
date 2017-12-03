#include "Zookeeper.h"
#include <vector>
#include <random>
#include <chrono>
#include <iostream>

int main() {
    std::vector<size_t> array;
    //std::random_device rd;
    //std::default_random_engine e1(rd());
    //std::uniform_int_distribution<size_t> uniform_dist(1, 1000000);
    for (size_t i = 0; i < 10000; i++) array.push_back(i+1000000);//uniform_dist(e1));

    auto begin = std::chrono::high_resolution_clock::now();
    Zookeeper keeper(4, array);
    for (auto number : keeper.GetPrimes()) std::cout << "Prime:" << number << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::milliseconds>(end - begin).count() << std::endl;

    return 0;
}

