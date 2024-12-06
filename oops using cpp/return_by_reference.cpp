//use of reference variables concept
#include<iostream>
using namespace std;
// function prototype
int& max(int &x, int &y); //max function returning a reference to an integer and parameters are
                          // passed by reference to  directly access the
                          // original variables  

int main() {
    
    //cout << max(2, 3);
    // issue: In C++, a reference is essentially an alias for a variable, and literals like 2 or 3 
    //cannot be aliased because they don’t have memory storage.

    int a = 2, b = 3;
    //cout << "max value: " << max(a, b) << endl;

    // modifications: Changes made to the returned reference will affect the original variable.
    max(a, b) = 10;
    cout << "a: " << a << ", b: " << b << endl;

    // The line max(a, b) = 10; modifies the larger variable (b) directly, demonstrating the
    // power of returning by reference.
    
    return 0;
}

int& max(int &x, int &y){
     
    if(x>y)
        return x;
    else
        return y; 
//  x and y are reference to a and b, they returns the reference to the large 
// variable not  acopy 
         
}
