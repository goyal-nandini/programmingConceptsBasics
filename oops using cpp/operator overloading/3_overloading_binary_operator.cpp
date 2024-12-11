// *****simplest, overloading +, - operator to add and subtract objects
// to add as a member function ✅✅
// to sub as a friend function ✅✅
/*As a rule in overloading of Binary operators the left hand operand is used to invoke the operator function and the right hand operand is passed as an argument*/
#include<iostream>
using namespace std;
class myClass{
    int value_1;
    friend myClass operator-(myClass, myClass);
    public:
        myClass(int v1 = 0) : value_1(v1) {}
        //operator function
        int operator+(myClass o){
            int temp = value_1+o.value_1;// here value_1 refers to object c1 and o.value_1 refers to object c2 
            // c1 takes the responsibility for invoking the function And the data members of c1 are directly 
            //while c2 plays the role of an argument that is passed to the function and the data members of c2 are accessed using dot operator.
            // --> also this->value_1(or simply value_1) refers to calling object
            return temp; // temp is to store the integer value
        }
        //The display function is added to the class to print the result of the subtraction. Without this, you wouldn’t be able to directly print a myClass object.
        void display(){
            cout << value_1;
        }
};
myClass operator-(myClass o1, myClass o2){
    return myClass(o1.value_1 - o2.value_1);// Return the result of subtraction as a new object(temporary object forms)
}
/* c1 - c2 ---> c1 is the object that calls the operator- function. It is passed as the first argument (o1) in the friend function.
c2 is passed as the second argument (o2) in the friend function.
----> o1.value_1 refers to the value_1 of c1 (the object invoking the operator).
----> o2.value_1 refers to the value_1 of c2 (the object passed as the argument)
*/
int main() {
    myClass c1(2);
    myClass c2(1);
    cout << "sum: " << c1 + c2 << endl; // calls c1.operator+(c2);
    // tip!! "this" in member functions refers to the calling object. here c1 is calling object 

    myClass c3 = c1 - c2; //calls operator-(c1, c2);
    cout << "subtraction: ";
    c3.display(); 
    return 0;
}