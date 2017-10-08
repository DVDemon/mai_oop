#include <cstdlib>
#include <iostream>
#include "SquareEquation.h"

int main(int argc, char** argv) {
    double a, b, c;

    std::cout << "Enter a:";
    std::cin >> a;

    std::cout << "Enter b:";
    std::cin >> b;

    std::cout << "Enter c:";
    std::cin >> c;
    try {
        SquareEquation se(a, b, c);

        double x1 = se.FindX1();
        double x2 = se.FindX2();
        std::cout << "X1=" << x1 << "\n";
        std::cout << "X2=" << x2 << "\n";
    } catch (WrongEquationException &ex) {
        std::cout << std::endl << "WrongEquationException:" << ex.what() << std::endl;
    } catch (WrongEquationException* d) {
        std::cout << std::endl << "WrongEquationException*:"<< d->what() << std::endl;
        delete d;
    }
    return 0;
}
