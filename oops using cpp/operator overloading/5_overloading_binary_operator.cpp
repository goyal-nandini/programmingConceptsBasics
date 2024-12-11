// overloading <<, >> operator using member function ❌
// *****simplest, overloading <<, >> operator using friend function✅
#include<iostream>
using namespace std;
class myClass{
    int value;
    friend istream& operator >> (istream& in, myClass &obj);
    friend ostream& operator << (ostream& out, myClass &obj);
    public:
        myClass() : value(0) {}
        // the issue explained in .md file!!
        // istream& operator >> (istream& in){
        //     cout << "Enter value";
        //     in >> value;
        //     return in;
        // }
        // ostream& operator << (ostream& out){
        //     out << value;
        //     return out;
        // }
};
istream& operator >> (istream& in, myClass &o){
    cout << "Enter value: ";
    in >> o.value;
    return in;
}
ostream& operator << (ostream& out, myClass &o){
    out << o.value;
    return out;
    }
int main() {
    myClass c1;
    cin >> c1;
    cout << c1;
    return 0;
}