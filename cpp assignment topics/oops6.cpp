//this pointer + dynamiclly creating object + adding class file to this program
//The this pointer is an implicit pointer available in non-static member functions of a class. It points to the current object that invoked the member function.
#include<iostream>
#include"oops6_1.cpp"
using namespace std;

class A{
    public:
    A(){
        cout << "The address of object of A is: " << this << endl;
    }
    void func(){
        cout << "The address of member function: " << this << endl;
    }
};
//An implicit pointer is something you don’t need to create or explicitly pass in your code—it is automatically provided by the programming language.
int main(){
    A a1, a2;
    a1.func();
    //here, this pointer automatically points to a1. Inside the func function, if you use this, it gives the address of a1.
    a2.func();
    // this automatically points to a2.

    // obj a1 se jo bhi call lg rhi hai(constructor, member function) this pointer same address store kr rha hai, which means "this pointer stores address of current object"
    // the "this" pointer stores a different address for each object.

    B b1;
    b1.setX(109);
    b1.display();

    // dynamically creating object 
    B* b2 = new B;   // Calls B(), implicit constructor call
    B* b3 = new B();  // Calls B(), explicit constructor call

    //B* b = new B;:-> Here, the compiler implicitly calls the default constructor of class B. It is a shorthand version of new B().
    //B* b = new B();:-> Here, the parentheses explicitly call the default constructor B().

    delete b2;  // Deallocating memory
    delete b3;  // Deallocating memory

    B* b4 = new B;
    //here in LHS, pointer b4 to an object of type B is created, b4 holds memory address of dynamically created object.
    // "new" allocates memory on the heap, When we write "new B", we are asking the compiler to allocate memory for an object of type B on the heap.
    
    return 0;
}