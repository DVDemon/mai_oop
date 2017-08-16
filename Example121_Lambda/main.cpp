#include <vector>
#include <iostream>

class MyLambda {
public:

    void operator()(int i) const {
        std::cout << i << " ";
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> elements;

    for (int i = 0; i < 10; i++) elements.push_back(i);

    // lambda
    auto lambda = [](int i) {
        std::cout << i << " ";
    };
    for (int i : elements) lambda(i);
    std::cout << std::endl;

    // without lambda
    MyLambda functor;
    for (int i : elements) functor(i);
    std::cout << std::endl;

    return 0;
}