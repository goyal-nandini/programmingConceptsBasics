// size of class (check again)
#include<iostream>
using namespace std;

class emptyClass{
    
};

class cars{
    string model; 
    int year; // 4
};

int main(){
    emptyClass e1;
    cout << "The size of empty class: " << sizeof(e1) << endl; // output 1
    emptyClass e2, e3;
    cout << &e2 << " " << &e3 << endl; 
    cout << "Address of e2: " << reinterpret_cast<uintptr_t>(&e2) << endl; // Decimal format
    cout << "Address of e3: " << reinterpret_cast<uintptr_t>(&e3) << endl; 


    cars c1;
    cout << "The size of class: " << sizeof(c1) << endl;
    cout << "Alignment of class: " << alignof(cars) << " bytes" << endl;

    return 0;
}