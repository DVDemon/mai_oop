#include "stdlib.h" // работа с памятью
#include "stdio.h" // работа с вводом и выводом
#include "string.h" // работа со строками

int a[10];
int *array_func(int val) {
//    int a[10];
    for (int i = 0; i < 10; i++) a[i] = val;
    return a;
}

int main(int argc, char** argv) {
    int *array = array_func(3);

    for (int i = 0; i < 10; i++)
        printf("Array is %d\n", *(array+i));

    return 0;
}

