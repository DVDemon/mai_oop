#include <cstdlib>
#include "MyClass.h"

int main(int argc, char** argv) {

    	MyClass a;  // Create object by Value
        a.Number = 3;
	a.doSomething();

	MyClass *a_ptr; // Pointer to the object

	a_ptr = new MyClass(); //malloc
	a_ptr->Number = 10;
	a_ptr->doSomething();
	delete a_ptr; //free

    return 0;
}

