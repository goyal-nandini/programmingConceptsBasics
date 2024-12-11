// little concept checking myself, got idea from book 
#include<iostream>
using namespace std;

class base{
       int a;
    protected:
        int b; 
    public:
        int c;
        void displayBase(){
            a = 30;
            cout << "hi, it's base class member function" << endl;
            cout << "value of a (private member) from base class: " << a << endl;
        }
        
};
class derived_1 : public base{ // public derivation
    protected:
        int d;
    public:
        int e;
        void displayDerived_1(){
            b = 40;
            cout << "hi, it's derived_1 class member function" << endl;
            cout << "value of b (protected member) from base class: " << b << endl;    
            cout << "value of c (public member) from base class: " << c << endl;    
        }
};
class derived_2 : protected derived_1{ // public derivation, here derived_1 is base class for derived_2
        int f;
    public:
        int g;
        void displayDerived_2(){
            displayDerived_1();
            e = 10;
            d = 60;
            f = 70;
            cout << "hi, it's derived_2 class member function" << endl;
            cout << "value of d (protected member) from derived_1(a base class) class: " << d << endl;
            cout << "value of e (public member) from derived_1(a base class) class: " << e << endl;
            cout << "value of f from its own class as private member: " << f << endl;
            cout << "value of g from its own class as public member: " << g << endl;
            

        }
};
int main(){
    derived_1 d1;
    derived_2 d2;
    d1.c = 20;
    d1.displayBase();
    d2.g = 50;
    d2.displayDerived_2();

    return 0;
}