#include <iostream>
#include <string>
#include <vector>

class MyCollection;

class MyPair
{
private:
	int id;
	std::string value;
	friend MyCollection;
public:
	MyPair(int i, const char* v) : id(i), value(v) {};
	void Print() { std::cout << "id=" << id << " ,Value=" << value << std::endl; }
};

class MyCollection
{
private:
	std::vector<MyPair> vector;
public:
	void Add(MyPair &&other) { vector.insert(vector.end(), other); } // good
	void Add(int id, const char* value) { vector.insert(vector.end(), MyPair(id, value)); } // bad

	void Print() { for (auto i : vector) i.Print(); } // good
	void Print2() { for (auto i : vector) std::cout << "id=" << i.id << " ,Value=" << i.value << std::endl; }

};

int main()
{
	MyCollection collection;
	// Ask, don't tell;
	collection.Add(1, "This is 1");

	// Tell, don't ask
	collection.Add(MyPair(2, "This is 2"));

	collection.Print();

	return 0;
}