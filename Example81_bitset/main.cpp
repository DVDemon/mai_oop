#include <iostream>
#include <bitset>   // заголовочный файл битовых полей

int main() {
    int number;
    std::cout << "Введите целое число от 1 до 255: ";
    std::cin >> number;

    std::bitset<8> message(number);
    std::cout << number << " = " << message << std::endl;

    std::bitset<8> bit2 = message;
    message = message.flip(); // поменять все биты на противоположные
    std::cout << "Инвертированное число: " << message << std::endl;

    std::bitset<8> bit3 = bit2 | message;
    std::cout << bit2 << " | " << message << " = " << bit3 << std::endl; // операция логического ИЛИ

    std::bitset<8> bit4 = bit3 & message;
    std::cout << bit3 << " & " << message << " = " << bit4 << std::endl; // операция логического И

    std::bitset<8> bit5 = bit3 ^ message;
    std::cout << bit3 << " ^ " << message << " = " << bit5 << std::endl; // операция исключающего ИЛИ


    std::bitset<64> hash(0);

    for (int i = 0; i < 64; i++)
        hash[i] = 1;
    std::cout << hash.to_ullong() << std::endl;


    return 0;
}