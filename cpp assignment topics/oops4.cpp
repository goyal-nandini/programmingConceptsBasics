// default constructor 
#include <iostream>
using namespace std;
// ##important:
// A constructor initializes an object by giving its data members initial values.
// A constructor is called automatically when you create an object.

class cars{
    string name;
    // constructor should be declared in public section
    public:
    cars(){
        cout << "First Constructor called!" << endl;
        name = "Doc Hudson";
        cout << name << endl;
    } 
};

class toys{
    
    public:
    int m, n;
    toys(); 
};
// constructor defined
toys :: toys(void){ 
    cout << "Second constructor is called!" << endl;
    m = n;
}

int main(){
    cars c1;
    //cout << c1.cars() << endl; // not valid
    //The constructor is automatically called when an object is created, and you don't call it manually like a normal function.

    toys t1;
    cout << "m = " << t1.m << ", " << "n = " << t1.n << endl;
     
    return 0;
}