#include <iostream>
#include <memory>

class A{
public:
  A(int a,int c){}
};

int main () {
  std::shared_ptr<A> a=std::make_shared<A>(122,12);

  std::shared_ptr<int> foo = std::make_shared<int> (10);
  // same as:
  std::shared_ptr<int> foo2 (new int(10));


  std::cout << "*foo: " << *foo << '\n';
  std::cout << "*foo2: " << *foo2 << '\n';

  return 0;
}
