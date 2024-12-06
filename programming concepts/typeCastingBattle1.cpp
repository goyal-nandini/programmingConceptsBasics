#include<iostream>
using namespace std;
int main(){
    int n = 22;
    float x = 3.14159;
    //1.
    x += n;  // x = 3.14159 + 22.0 = 25.14159 
    // prints 25.1416
    cout << x << endl; 
    cout << x-2 << endl; // 25.14159 - 2.0 = 23.14159
    // prints 23.1416
    // issue explained below
    // 2.
    float p = int(x);
    cout << p << endl; // 25 (25.14159 to 25) -> conversion from float to int by int(x)
    //then to get store in p it should print 25.0 but 25 is displayed.
    //issue explained below
    


    char q = int('?');
    cout << q << endl; // ? (first ? converts to 63 then to ? to get store in q) (me)

    int s = 12.0987; // s has 12 stored in it
    // typecasting to float
    cout << float(s) << endl; // 12 (should be 12.0)
    // converts the integer s to a float before printing. This means 12 is converted to 12.0 internally, but how it's printed 
    //depends on cout.

    //Default cout Behavior:
    // By default, cout may display 12.0 as 12 because it's a whole number. C++ might not show the .0 unless you specifically
    // instruct it to do so.(another file for this)

    double v = 1234.56789;
    int w = int(v);
    cout << "v = " << v << ", w = " << w;
    // v = 1234.57, w = 1234

    // By default, cout prints floating-point numbers with a precision of 6 significant digits.
    //This means it will show up to 6 digits total (before and after the decimal point).
    //When cout prints a floating-point number with more digits than the precision allows, it rounds the last digit.
    // he reason 1234.56789 is printed as 1234.57 is due to the rounding rule, where digits are rounded up if the following digit 
    //is 5 or greater. In this case, the digit after 6 is 7, so 1234.56789 rounds up to 1234.57.
}