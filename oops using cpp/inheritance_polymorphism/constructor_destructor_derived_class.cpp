#include<iostream>
using namespace std;
class base1{
    public:
        base1() {
            cout << "constructor without parameter from base1 class" << endl;
        }
        base1(int x) {
            cout << "constructor with parameter " << x << " from base1 class"  << endl;
        }
        ~base1(){
            cout << "destructor from base1 class" << endl;
        }
};
class base2{
    public:
        base2() {
            cout << "constructor without parameter from base2 class" << endl;
        }
        base2(int y) {
            cout << "constructor with parameter " << y << " from base2 class"  << endl;
        }
        ~base2(){
            cout << "destructor from base1 class" << endl;
        }
};
class derived : public base2, public base1{ // "derived class header line"
    int value;
    public:
        derived(){
            cout << "constructor without parameter from derived class" << endl;
        }
        derived(int z, int a, int b) : 
        base1(b), base2(a) { // this is "function call", it's parameter has no data type, this is "derived constructor header line"
            cout << "constructor with parameter " << z << " from derived class" << endl;
        }
        ~derived(){
            cout << "destructor from derived class" << endl;
        }
};
int main() {
    // derived d1;
    derived d2(30, 50, 70);
    // phle "base2" constructor print hua then "base1" constructor then "derived" constructor!!
    // b/c "base2 constructor" is derived first in "derived class header line"
    // destructor bilkull oppsosite hoga
    return 0;
}