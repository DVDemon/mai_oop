#include <iostream>
#include "Primer.h"
#include "Zookeeper.h"

Zookeeper::Zookeeper(size_t count, std::vector<size_t> &param) : _array(param), thread_count(count) {
}

void Zookeeper::AddResult(size_t number) {
    std::lock_guard<std::mutex> lock(mtx);
    _primes.push_back(number);
}

size_t Zookeeper::Get(Primer *primer) {
    std::lock_guard<std::mutex> lock(mtx);
    if (current >= _array.size()) primer->Die();
    else {
        return _array[current++];
    }
    return -1;
}

std::vector<size_t> & Zookeeper::GetPrimes() {
    current = 0;
    _primes.clear();
    
    // start work
    for (size_t i = 0; i < thread_count; i++)
        threads.push_back(std::shared_ptr<std::thread>(new std::thread(Primer(this))));

    //finish work
    for (auto i : threads) if (i->joinable()) i->join();
    return _primes;
}

