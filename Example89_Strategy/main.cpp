#include <iostream>
#include <string>
#include <algorithm>

class StrategyIF {
public:
    virtual void algorithmInterface(const char* parm) = 0;
};

class ConcreteStrategy1 : public StrategyIF {
public:

    void algorithmInterface(const char* param) override {
        std::string msg = param;
        std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
        std::cout << msg << std::endl;
    }
};

class ConcreteStrategy2 : public StrategyIF {
public:

    void algorithmInterface(const char* param) override {
        std::string msg = param;
        std::transform(msg.begin(), msg.end(), msg.begin(), ::tolower);
        std::cout << msg << std::endl;
    }
};

template <class StrategyIF> class Context {
protected:
    // Reference to the strategy.
    StrategyIF strategy;

public:
    // Register reference to strategy on construction.
    Context(StrategyIF param) : strategy(param) {
    }

    void contextInterface(const char *parm) {
        strategy.algorithmInterface(parm);
    }
};

int main() {
    ConcreteStrategy1 strategy1;
    ConcreteStrategy2 strategy2;

    Context<ConcreteStrategy1> context1(strategy1);
    Context<ConcreteStrategy2> context2(strategy2);

    context1.contextInterface("Hello world!");
    context2.contextInterface("Hello world!");


    return 0;
}
