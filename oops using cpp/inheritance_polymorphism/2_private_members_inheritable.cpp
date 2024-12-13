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
class derived_2 : protected derived_1{ // protected derivation, here derived_1 is base class for derived_2
        int f;
    public:
        int g;
        void displayDerived_2(){
            displayBase(); //---> correct
            c = 20;
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
    // d1.c = 20; //---> issue 
    // d1.displayBase(); ----> correct
    

    d2.g = 50;
    d2.displayDerived_2();

    return 0;
}
/*here a, b, c, displayBase() -----> are of base class
b ---> become protected to derived_1 class
➡️c, displayBase() ----> become public to derived_1 class

d, e, displayDerived_1() ----> are of derived_1 class
now, also 
b, c, displayBase() ----> are of derived_1 class
d ----> become protected to derived_2 class
e, displayDerived_1() ----> become protected to derived_2 class
b ----> protected member of derived_2 class
➡️c, displayBase() become protected to derived_2 class

f, g, displayDerived_2() ---> are of derived_2 class
*/