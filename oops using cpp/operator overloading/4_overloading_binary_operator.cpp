// overloading * operator in scalar multiplication using friend function
#include<iostream>
using namespace std;
class myClass{
    int value;
    int vector[3]; // Array to hold vector values
    friend myClass operator * (myClass& obj, int num);
    friend myClass operator * (int num, myClass & obj);
    public:
        // myClass() {} --> also works!!
        myClass() { // Default constructor with zero initialization
            for (int i = 0; i < 3; i++) {
                vector[i] = 0;
            }
        }
        //Ensures that all member variables are initialized to predictable default values (in this case, zeros).

        // myClass(int set_value) : value(set_value) {} --> no need
        myClass(int *set_vector){ // constructor to initialize vector
            for (int i=0; i<3; i++){
                vector[i] = set_vector[i];
            }
        } 
        void get_result(){
            cout << "( ";
            for(int i=0; i<3; i++){
                cout << vector[i] << " ";
            }
            cout << ")";
            cout << endl;
        }
};
myClass operator * (myClass & o, int n){
    myClass v;
    for(int i=0; i<3; i++){
        v.vector[i] = n * o.vector[i];
    }  
    return v;   
}
myClass operator * (int n, myClass & o){
    myClass v;
    for(int i=0; i<3; i++){
        v.vector[i] = n * o.vector[i];
    }  
    return v;   
}
int main() {
    int x[3] = {3, 7, 8};
    
    //direct initialization
    //myClass c2 = x; --> valid 

    //copy constructor
    myClass c2(x); // Initialize c1 with vector x
    //The constructor myClass(int* set_vector) is called directly with the argument x.

    myClass c3 = c2 * 3; // scalar multiplication, equivalent to operator*(c2, 3)
    myClass c4 = 4 * c2; //equivalent to operator*(4, c2)
    c3.get_result();
    c4.get_result();
    return 0;
}