#include <iostream>
using namespace std;
int main()
{
    // implicit casting 
    // All the data types of the variables are upgraded to the data type of the variable with largest data type.
    // bool -> char -> short int -> int -> unsigned int -> long -> unsigned -> long long -> float -> double -> long double
//The data types are ordered from the smallest (in terms of memory size and precision) to the largest. 

// bool (typically 1 byte)
// char (typically 1 byte)
// short (typically 2 bytes)
// int (typically 4 bytes)
// unsigned int (typically 4 bytes)
// long (typically 4 or 8 bytes, depending on the platform)
// unsigned long (typically 4 or 8 bytes)
// long long (typically 8 bytes)
// unsigned long long (typically 8 bytes)
// float (typically 4 bytes, precision of about 7 decimal digits)
// double (typically 8 bytes, precision of about 15 decimal digits)
// long double (typically 12 or 16 bytes, precision of about 19 decimal digits)
    bool b = true + 1;
    cout << "bool b = " << float(b) << endl;
    // So, true + 1 is equivalent to 1 + 1, which results in 2 as an int.
    //However, b is a bool, which can only hold true or false. Any non-zero value assigned to a bool is interpreted as true.
    //Therefore, the value 2 is implicitly converted to true when assigned to b.
    char c = 'A';
    cout << "Char c = " << c << endl;

    short k = c;
    cout << "short k = " << k << endl;

    int m = k;
    cout << "int m = " << m << endl;

    long n = m;
    cout << "long n = " << n << endl;

    float x = m;
    cout << "float x = " << x << endl;

    double y = x;
    cout << "double y = " << y << endl;
    // type conversion 
    // implicit type conversion 
    // explicit type conversion(another file)

    return 0;
}
