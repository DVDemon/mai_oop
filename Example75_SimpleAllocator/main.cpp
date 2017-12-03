#include <iostream>
#include <memory>
#include <chrono>
#include <vector>
#include "TAllocationBlock.h"

bool use_allocator = false;

class Item {
private:
    static TAllocationBlock allocator;

    static int get_number() {
        static int number = 0;
        return ++number;
    };
    bool allocated_with_allocator;
    int number;
    //char budder[10000];
public:

    Item() {
        allocated_with_allocator = use_allocator;
        number = get_number();
        //std::cout << "Created:" << number << std::endl;
    }

    virtual ~Item() {
        //std::cout << "Deleted:" << number << std::endl;
    }

    void* operator new(size_t size) {

        if (use_allocator)
            return allocator.allocate();
        else
            return malloc(size);
    }

    void operator delete (void *p) {
        //std::cout << "Delete";
        if (((Item*) p)->allocated_with_allocator)
            allocator.deallocate(p);
        else
            free(p);

    }
};


TAllocationBlock Item::allocator(sizeof (Item), 100000);

int main(int argc, char** argv) {

    Item * vector[100000];
    for (int i = 0; i < 100000; i++) vector[i] = nullptr;

    // Experiment one
    /*
    for (int j = 0; j < 16; j++) {
        use_allocator = (j % 2 == 0);

        if (use_allocator) std::cout  << "Allocator        ";
        else std::cout  << "Without allocator";
        
        auto begin = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++) vector[i] = new Item();
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "New:" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() ;
        
        begin = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++) delete vector[i];
        end = std::chrono::high_resolution_clock::now();
        std::cout << " Delete:" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    }
/*/   
    // experiment two
   for (int i = 0; i < 100000; i++) vector[i] = nullptr;

    for (int j = 0; j < 16; j++) {
        use_allocator = (j % 2 == 0);

        if (use_allocator) std::cout  << "Allocator        ";
        else std::cout  << "Without allocator";
        
        auto begin = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++) 
        {
            if(vector[i]!=nullptr) delete vector[i];
            vector[i] = new Item();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << " New/Delete:" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    }
//*/
    return 0;
}

