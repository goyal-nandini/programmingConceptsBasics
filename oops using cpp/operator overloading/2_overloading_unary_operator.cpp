/* overloading ++, --(as it is as++) 
*****pre-increament using friend function
and *****post-increment object as a member function --->
#### Requires a dummy int parameter to distinguish it from pre-increment.
We never actually pass a value to it when calling obj++,
Returns the object's original state before modification, while modifying the 
object afterward.*/
#include<iostream>
using namespace std;
class myClass{
    int value;
    // friend function for pre-increment
    friend myClass operator++(myClass &obj);
    public:
        //  It directly assigns the value of v to the member variable value.
        myClass(int v = 0) : value(v) {}
        void display(){
            cout << value << endl;
        }
        // post-increment
        int operator++(int);
};
//operator function(pre-increment) as friend function
myClass operator++(myClass &obj){
    myClass o(++obj.value);
    return o;
}
//operator function(post-increment) as member function
int myClass :: operator++(int item){
    return item++;
}
int main() {
    myClass c1(78), c2;
    //invoking corresponding operator functions

    c1++; // post-increment
    c1.display(); // 78
    int a = 23;
    int b = a++;
    cout << a << endl; //24
    cout << b; //23

    c2 = ++c1; //pre-increment
    c2.display(); // 79
    return 0;
}