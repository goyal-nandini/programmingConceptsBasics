/*protected --> third access modifier

1. protected members of base class ---> "protected" in "public derivation" i.e. 
   Visible to member functions of its own and of the derived class

   public member of base class ---> "public" in "public derivation"

2. protected members of base class ---> "private" in "private derivation"

   public member of base class ---> "private" in "private derivation"
*/  
#include<iostream>
using namespace std;

class base{
    protected:
        int a; 
    public:
        int b;
        void displayBase(){
            cout << "it's base class member function" << endl;
        }
        
};
class derived : public base{ // public derivation
    int c;
    public:
        int d;
        void displayDerived(){
            a = 10; // "a", protected member is accessed by member function only
            cout << "it's derived class member function" << endl;  
            cout << "a from base class as protected member of derived class: " << a << endl;  
            cout << "b from base class as public member of derived class: " << b << endl;  
        }
};
int main() {
    derived d1;
    d1.b = 20;
    d1.displayBase();
    d1.displayDerived();
    return 0;
}