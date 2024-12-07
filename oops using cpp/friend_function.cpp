/*
******friend function,
adding complex numbers,
i have used ******static to count the number of complex numbers,
now it is printing 2 as count(u know the reason, as setNum would be called twice) but i want it should count the new complex number after summation so here is the concept of 
******"returning an object" {changes made majorly in friend function only!}
""it means you need to explicitly create another myClass object for the sum""
A good practice of using reference variables for memory management.
If you're working with class objects, it's better to pass them by reference to avoid copying large amounts of data.
 */ 

#include<iostream>
using namespace std;

class myClass{
        int x;
        int y;
        static int count;
        // friend void complexSum(myClass, myClass);
        friend myClass complexSum(const myClass&, const myClass&);
        public:
            void setNum(int r, int c){ // real part and complex part
                this->x = r;
                this->y = c;
                ++count; 
            }
            void displayNum(){
                cout << "num " << count << ": " << x << " + " << y << "i" << endl;
            }
            static void getCount(){
                cout << "count of complex numers is: " << count << endl;
            }
};
// friend function to add two complex numbers and return the sum as a new object
myClass complexSum(const myClass &c1, const myClass &c2){
    // cout << "sum is: " << c1.x+c2.x << " + " << c1.y+c2.y << "i" << endl;
    myClass result; // created an object of myClass
    result.setNum(c1.x + c2.x, c1.y + c2.y);
    return result; 
}
// The const ensures that complexSum does not modify the original objects

int myClass :: count;

int main() {

    myClass c1, c2, sum;
    c1.setNum(2, 4);
    c1.displayNum();
    c2.setNum(4, 6);
    c2.displayNum();

    sum = complexSum(c1, c2);
    cout << "sum of complex number is: ";
    // displayNum(); we can't access this member function, we have to create an object, sum
    sum.displayNum();

    //complexSum(c1, c2).displayNum(); ----> valid!!
    
    myClass :: getCount(); 
    return 0;
}