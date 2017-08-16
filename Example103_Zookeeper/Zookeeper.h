#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H
#include "Primer.h"

#include <thread>
#include <vector>
#include <memory>

#include <mutex>


class Zookeeper {
protected:
    std::vector<std::shared_ptr<std::thread>> threads;
    std::vector<size_t> &_array;
    std::vector<size_t> _primes;
    size_t current;
    size_t thread_count;
    std::mutex mtx;
public:

    Zookeeper(size_t count,std::vector<size_t> &param) ;
    size_t Get(Primer *primer);
    void AddResult(size_t number);
    std::vector<size_t> & GetPrimes() ;
};

#endif /* ZOOKEEPER_H */

