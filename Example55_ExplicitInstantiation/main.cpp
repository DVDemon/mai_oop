#include "Stack.h"
#include "MyClass.h"

int main(int argc, char** argv) {

    //*
    MyStack<MyClass*,&deleterMyClassPtr> stack;
    MyClass * item = NULL;

    stack.Push(new MyClass("Hello"));
    stack.Push(new MyClass("World"));
    stack.Push(new MyClass("!"));

    item = stack.Pop();
    item->print();
    delete item;
    
    item = stack.Pop();
    item->print();
    delete item;
    
    
    item = stack.Pop();
    item->print();
    delete item;
    
 
    //*/
      
    
    MyStack<MyClass,&deleterMyClass> stack2;

    stack2.Push(MyClass("Goodbye"));
    stack2.Push(MyClass("World"));
    stack2.Push(MyClass("!"));

    stack2.Pop().print();
    stack2.Pop().print();
    stack2.Pop().print();
     //*/
 
    return 0;
}

