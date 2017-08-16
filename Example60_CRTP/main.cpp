#include <iostream>

template <class T> class SafeWorker {
public:

    void action() {
        try {
            //dynamic_cast<T*>(this)->action_impl();
            ((T*)this)->action_impl();
        } catch (...) {
            std::cout << "Unexpected exception" << std::endl;
        }
    }

};

class GoodWorker : public SafeWorker<GoodWorker> {
public:

    void action_impl() {
        std::cout << "Some action ..." << std::endl;
    }
};

class EvilWorker : public SafeWorker<EvilWorker> {
public:

    void action_impl() {
        throw *this;
    }
};

int main(int argc, char** argv) {

    SafeWorker<EvilWorker> zz;
    zz.action();
    
    GoodWorker g;
    g.action();

    EvilWorker e;
    e.action();

    return 0;
}

