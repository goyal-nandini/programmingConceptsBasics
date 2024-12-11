//When a base class is "privately" inherited by a derived class, "public members" of the base class become "private 
//members" of the derived class and 
//therefore the public members of the base class can only be accessed by the member functions of the derived class.
//they are "inaccessible" to the "objects of derived class".

#include<iostream>
using namespace std;
class base{
    int a; // private, not inheritable
    public:
        int b;
        void displayBase(){
            cout << "hi, it's base class member function" << endl;
        }
        
};
class derived : private base{ // private derivation
    int c = 10;
    public:
        void displayDerived(){
            b = 20; // b("public member") from base class, now is "private member" of derived class i.e. accessed by member functions only
            cout << "hi, it's derived class member function" << endl;
            cout << "value of b (of base class) displayed from derived class memeber function: " << b << endl; 
            cout << "value of c is: " << c << endl;
            cout << "calling public members of base class: " << endl;
            displayBase();
        }
};
int main() {
    derived d1;
    d1.displayDerived();
    
    return 0;
}