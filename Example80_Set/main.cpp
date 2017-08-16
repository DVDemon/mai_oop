#include <iostream>
#include <set>  // заголовочный файл множеств и мультимножеств
#include <iterator>
 

int main()
{
    std::set<char> mySet; // объявили пустое множество
 
    // добавляем элементы в множество
    mySet.insert('I');
    mySet.insert('n');
    mySet.insert('f');
    mySet.insert('i');
    //mySet.insert('n');
    //mySet.insert('i');
    mySet.insert('t');
    mySet.insert('y');
 
    for( auto i: mySet)  std::cout << i << " ";
    std::cout << std::endl;
    mySet.erase('i');
    
    for( auto i: mySet)  std::cout << i << " ";
    std::cout << std::endl;
    
    if(mySet.find('I')!=mySet.end()) std::cout << "Found I" << std::endl;
    if(mySet.find('Z')!=mySet.end()) std::cout << "Found Z" << std::endl;
    return 0;
}