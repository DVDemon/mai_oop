#include <iostream>

template <class T> class SafeWorker {
public:

    void action() {
        std::cout << "Begin" << std::endl;
        try {
            //dynamic_cast<T*>(this)->action_impl();
            ((T*)this)->action_impl();
        } catch (...) {
            std::cout << "Unexpected exception" << std::endl;
        }
        std::cout << "End" << std::endl;
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

    GoodWorker g;
    g.action();

    EvilWorker e;
    e.action();
   // e.action_impl();

    return 0;
}

