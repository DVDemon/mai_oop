#include <iostream>
#include <deque>        // подключаем заголовочный файл деков
#include <iterator>     // заголовок итераторов
#include <string>       // заголовочный файл для работы со строками типа string


int main() {
    std::deque<std::string> myDeque; // создаем пустой дек типа string
    myDeque.push_back(std::string("World ")); // добавили в дек один элемент типа string
    std::cout << "Количество элементов в деке: " << myDeque.size() << std::endl;

    myDeque.push_front("Hello "); // добавили в начало дека еще один элемент
    myDeque.push_back(" !!!"); // добавили в конец дека элемент 
    std::cout << "Количество элементов в деке изменилось, теперь оно = " << myDeque.size() << std::endl;

    std::cout << "\nВведенный дек: ";
    for(auto i:myDeque) std::cout << i << " ";


    std::cout << myDeque.front() << std::endl;
    myDeque.pop_front(); // удалили первый элемент
    myDeque.pop_back(); // удалили второй элемент
    myDeque.resize(1, "empty"); // увеличиваем размер дека до 6 элементов, новые элементы заполняются словом "empty"

    std::cout << "\nБыли удалены первый и последний элементы дека, вот что осталось: ";
    for (int i = 0; i < myDeque.size(); i++) {
        std::cout << myDeque[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}