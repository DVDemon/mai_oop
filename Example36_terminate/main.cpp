#include <iostream>
using namespace std;

void term_func() {
    cout << "term_func was called by terminate." << endl;
    exit(-1);
}

int main() {
    try {
        set_terminate(term_func);
        throw "Out of memory!"; // No catch handler for this exception
    } catch (int) {
        cout << "Integer exception raised." << endl;
    }
    return 0;
}

