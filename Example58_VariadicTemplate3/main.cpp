#include <iostream>

class PrinterInt
{
private:
	int value;
public:
	PrinterInt(int a) : value(a) {};
	void Print() { std::cout << value; }
};

class PrinterString
{
private:
	const char* value;
public:
	PrinterString(const char* a) : value(a) {};
	void Print() { std::cout << value; }
};

class PrinterEnd
{
public:
	void PrintEnd() { std::cout << std::endl; }
};


class PrinterBefore
{
public:
	void PrintBefore() { std::cout << "Value:"; }
};

class PrinterAll
{
public:
	void PrintBefore() { std::cout << "Here we go:"; }
	void PrintEnd() { std::cout << std::endl << "Thats all!" << std::endl; }
};


template <class... BaseClasses> class Printer : public BaseClasses... {
public:

	Printer(BaseClasses&&... base_classes) : BaseClasses(base_classes)... 
	{
		//PrintBefore();
		//Print();
		//PrintEnd();
	}
	
};

int main(int argc, char** argv) {

    Printer<PrinterBefore, PrinterInt, PrinterEnd> 
         p1(PrinterBefore(), PrinterInt(5), PrinterEnd());
    
    p1.PrintBefore();
    p1.Print();
    p1.PrintEnd();

    

    Printer<PrinterAll, PrinterString> p3(PrinterAll(), PrinterString("Hello world!"));
      
    p3.PrintBefore();
    p3.Print();
    p3.PrintEnd();

    
    return 0;
}

