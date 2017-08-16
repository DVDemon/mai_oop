#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>

int main(int argc, char* argv[]) {
    std::vector<int> elements;
    int count = 0;

    auto lambda =[count]() mutable -> int // [&count] 
        {
            //std::cout << "Count:" << count << std::endl;
            return count++;
        };
        
    for (int i = 0; i < 10; i++) elements.push_back(lambda());


    std::ostream_iterator<int> os(std::cout, " ");
    std::copy(elements.begin(), elements.end(), os);
    std::cout << std::endl << "count=" << count << std::endl;

    return 0;
}
