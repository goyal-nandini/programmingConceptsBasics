// single inheritance -> visibilty - public
// derived class has "publically inherited" the base class, so it's "public members" only acts "publically" 
//in derived class

#include<iostream>
using namespace std;
class base{
    int a; // private, not inheritable
    public:
        int b;
        void displayBase(){
            cout << "it's base class member function" << endl;
        }
        
};
class derived : public base{ // public derivation
    int c = 10;
    public:
        void displayDerived(){
            cout << "it's derived class member function" << endl;
            cout << "value of b (of base class) displayed from derived class: " << b << endl; // b can be used here
            cout << "value of c is: " << c << endl;
        }
};
int main() {
    derived d1;
    d1.displayBase(); 
    d1.b = 20;
    d1.displayDerived();
    return 0;
}