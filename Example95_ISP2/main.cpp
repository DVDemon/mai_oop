#include <iostream>
#include <string>

class IWine {
protected:
    std::string wine;
public:

    IWine(const char * value) : wine(value) {
    }    
    const char* Value() {
        return wine.c_str();
    }
};

class ICoffe {
protected:
    std::string coffe;

public:
    ICoffe(const char * value) {
        coffe = "A cup of ";
        coffe += value;
    }

    const char* Value() {
        return coffe.c_str();
    }
};

template <class... Tail> class Menu {
public:
    void print() {}
};

template <class A, class ... Tail>
class Menu<A, Tail...> : public Menu<Tail ...> {
public:
    A value;
    
    Menu(A a, Tail ... tail) : value(a), Menu<Tail...>(tail...) {
    }

    void print() {
        std::cout << "Item:" << value.Value() << std::endl;
        Menu < Tail...> &next = static_cast<Menu < Tail...>&> (*this);
        next.print();
    }
};

int main() {

    Menu<IWine, ICoffe,IWine> menu("vodka", "americano","rassol");

    menu.print();
    return 0;
}

