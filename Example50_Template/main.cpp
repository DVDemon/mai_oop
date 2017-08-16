#include <iostream>


template <class T> class Print
{
 public:
	 Print(T value)
	 {
		 std::cout << "Value:" << value << std::endl;
	 };
};


int main(int argc, char** argv) {
    //Print<int> A(10);
    //Print<const char*> B("Hello world!");
    
    //Print<Print<int>> a(Print<int>(10));
    
    return 0;
}

