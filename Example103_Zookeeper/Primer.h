#ifndef PRIMER_H
#define PRIMER_H

#include <mutex>
class Zookeeper;

class Primer {
protected:
    Zookeeper *zoo;
    bool alive;
    std::mutex mtx;
    bool isPrime(int number);
    bool isAlive();
public:
    Primer(Zookeeper *zookeeper) ;
    Primer(const Primer &other);
    void Die();
    void operator()();
};

#endif /* PRIMER_H */

