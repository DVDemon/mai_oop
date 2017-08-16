#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    std::vector<int> v(5, 100);

    std::cout << "vector:" << std::endl;
    for (int i : v) std::cout << i << std::endl;

    v.push_back(101);
    std::cout << "vector:" << std::endl;
    for (int i : v) std::cout << i << std::endl;

    std::vector<int>::iterator it = v.begin();

    it++;
    v.insert(it, 99);
    std::cout << "vector:" << std::endl;
    for (int i : v) std::cout << i << std::endl;

    for (it = v.begin(); it != v.end();) {
        if (*it == 100) v.erase(it);
        else it++;
    };

    std::cout << "vector:" << std::endl;
    for (int i : v) std::cout << i << std::endl;



    return 0;
}

