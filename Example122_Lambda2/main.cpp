#include<iostream>
#include <vector>
#include <iterator>

int main(int argc, char* argv[]) {
    std::vector<int> elements;
    std::vector<double> results;

    for (int i = 0; i < 10; i++) elements.push_back(i);
    //*
    auto transform = [](int i) ->double {
        if (i < 5) return i + 1.0;
        else
            if (i % 2 == 0) return i / 2.0;
        else
            return i*i;
    };

    for (int i : elements) results.push_back(transform(i));

    /*/
    for(int i: elements) results.push_back([](int i) ->double {
        if (i < 5) return i + 1.0;
        else
            if (i % 2 == 0) return i / 2.0;
        else
            return i*i;
    }(i));
    //*/

    std::ostream_iterator<double> out(std::cout, " ");
    std::copy(results.begin(), results.end(), out);
    std::cout << std::endl;

    return 0;
}