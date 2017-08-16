#include "Primer.h"
#include "Zookeeper.h"

Primer::Primer(Zookeeper *zookeeper) {
    zoo = zookeeper;
    alive = false;
}

Primer::Primer(const Primer &other) {
    zoo = other.zoo;
    alive = other.alive;
}

bool Primer::isAlive() {
    std::lock_guard<std::mutex> lock(mtx);
    return alive;
}

void Primer::Die() {
    std::lock_guard<std::mutex> lock(mtx);
    alive = false;
}

void Primer::operator()() {
    alive = true;

    while (isAlive()) {
        int number = zoo->Get(this);
        if (isAlive()) if(isPrime(number)) zoo->AddResult(number);
    }
}

bool Primer::isPrime(int number){
    int i=2;
    bool isPrime = true;
    
    while((i<number-1)&&isPrime)
    {
        if(number%i==0) isPrime=false;
        i++;
    }
    return isPrime;
}
