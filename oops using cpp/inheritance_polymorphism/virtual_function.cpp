#include<iostream>
using namespace std;
class base{
    public:
        void display(){
            cout << "display base" << endl;
        }
        virtual void show(){
            cout << "show base" << endl;
        }
        // empty virtual function
        // virtual void display() {} 
};
class derived : public base{
    public:
        void display(){
            cout << "display derived" << endl;
        }
        void show(){
            cout << "show derived" << endl;
        }
};
int main() {
    base b;
    derived d;
    base * bptr;
    bptr = &d;
    bptr->show(); // calling show of derived class b/c of virtual function show() o/w see
    bptr->display(); //calling display of base class b/c of default behaviour the base class pointer refering derived class object will show up the member function of base class

    // i want display of derived class
    derived * dptr;
    dptr->display();

    bptr = &b;
    bptr->display(); //calling display of base class
    bptr->show();  //calling show of base class

    return 0;
}