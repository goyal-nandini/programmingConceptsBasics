// = is a binary operator
//we can't overload = using friend function
//The assignment operator needs access to the left-hand object (this) to change its data.
//A friend function cannot act on "this" because it’s not tied to any specific object. 
//A friend function works outside the class. It does not belong to any specific object so it does not have 
//"this" pointer to refer to the left hand object. Since the assignment operator needs to change the left hand 
//object directly only a "member function" can do it.
 
#include<iostream>
using namespace std;
class myClass{
    int value;
    public:
        myClass(int v = 0) : value(v) {}
        myClass& operator = (myClass & o){
            if(this == &o) // check for self assignmnent
                return *this;
            value = o.value;
            return *this;
        }
        void display(){
            cout << this << endl; // same address as of "c1"
            cout << value << endl;
        }     
};
int main() {
    myClass c1(12);
    myClass c2(10);

    c1 = c2; // c1.operator=(c2)
    c1.display();
    cout << &c1 << endl; // same address as of "this"
    return 0;
}