#include <future>
#include <vector>
#include <iostream>
#include <cmath>

#define STEP 1000000

int main() {
    double val = 0;
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::future < double>> results;
    for (int i = 0; i < 100; i++)
        results.push_back(std::async([i]() -> double {
            double result = 0;
            for(int j=1;j<=STEP;j++) result+= std::log10(i*STEP+j);
            return result;
        }));

    for (auto &i : results) val+=i.get();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel time:" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    std::cout << "Result:" << val << std::endl;

    val = 0;
    start = std::chrono::high_resolution_clock::now();   
    for (int i = 1; i <= 100*STEP; i++) val += std::log10(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Normal time:" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    std::cout << "Result:" << val << std::endl;
    
    return 0;
}

