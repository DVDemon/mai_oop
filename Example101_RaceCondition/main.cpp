#include<thread>
#include<iostream>
#include <random>

typedef bool comparator(int, int);

void sort(int* array, size_t size, comparator c) {

    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - 1; j++) {
            if (c(array[j], array[j + 1])) {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1];
            }
        }
}

bool less(int a, int b) {
    return a<b;
}

bool more(int a, int b) {
    return a>b;
}

int main(int argc, char** argv) {
    int array[100];

    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    for (int i = 0; i < 100; i++) array[i] = uniform_dist(e1);



    //sort(array, 100, more);


    // Конкурентный доступ к данным: что будет результатом сортировки?
    std::thread s1(sort, array, 100, less);
    std::thread s2(sort, array, 100, more);

    s1.join();
    s2.join();

    for (int i = 0; i < 100; i++) std::cout << array[i] << std::endl;
    return 0;
}

