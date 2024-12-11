// *****simplest, overloading +, -
// negation
#include <iostream>
using namespace std;
class myClass
{
    int value;

public:
    //Constructor to initialize the value
    myClass(int value)
    {
        this->value = value;
    }
    // operator function as a member function
    void operator-()
    {
        value = -value; 
    }
    void operator+();
    void display()
    {
        cout << value << endl;
    }
};
void myClass :: operator+()
    {
        value = +value;
    }
int main()
{

    myClass c1(23), c2(-45);
    // invoking operator function
    -c1; // c1.operator-(23);
    +c2; // c2.operator+(-45);
    c1.display();
    c2.display();

    return 0;
}