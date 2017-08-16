#include <iostream>

int main(int argc, char** argv) {

    int array[] = {1,2,3,4,5};
    
    for(int i:array) std::cout<< "[" << i << "]";
 
    int *array2 = new int[2];
    array2[0]=1;
    array2[1]=2;
      
    //  не сработает, поскольку не определена длина массива
    for(int i:array2) std::cout<< "[" << i << "]";
    
    delete array2;
    
    return 0;
}

