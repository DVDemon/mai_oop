#include <iostream>
#include <map>

int main(int argc, char** argv) {

    std::map<const char*,int> age;
    
    age["Иванов"] = 18;
    age.insert(std::pair<const char*,int>("Петров",21));
    age.insert(std::pair<const char*,int>("Сидоров",108));

    age.insert(std::pair<const char*,int>("Иванов",98));
  
    
    for(std::pair<const char*,int> value:age) 
        std::cout << "Age of " <<value.first << "=" << value.second << std::endl;

    age.erase("Петров");
    std::cout << "Без Петровых: " << std::endl;
    
    for(auto value:age) 
        std::cout << "Age of " <<value.first << "=" << value.second << std::endl;

    return 0;
}

