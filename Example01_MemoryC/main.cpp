

#include "stdlib.h" // работа с памятью
#include "stdio.h" // работа с вводом и выводом
#include "string.h" // работа со строками

int main(int argc, char** argv) {
    // выделяем память
    char *pointer = (char*) malloc(sizeof (char)*100);
    // копируем в память данные
    strcpy(pointer, "Hello World!");
    // получаем данные из памяти
    printf("%s", pointer);
    // освобождаем указатель
    free(pointer);
    // ждем нажатия любой клавиши
    getchar();

    return 0;
}


