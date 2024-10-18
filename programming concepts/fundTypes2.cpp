#include <iostream>
using namespace std;
// use of int(), <climit>, sizeof, <cfloat>, typecasting

int main()
{
    char upCase = 'A';
    char lowCase = 'a';
    cout << "upcase is: " << upCase << ", int(upCase) is: " << int(upCase) << "\n";
    cout << "lowCase is: " << lowCase << ", int(lowCase) is: " << int(lowCase) << endl;
    // type cast operator int() is used to reveal the corresponding integer value.
    char q = '?';
    cout << int(q) << endl;
    cout << int('/') << endl;

    // In C++, the following casting functions can be used:

    // int(): Converts a value to an integer. For example, int(3.14) would convert to 3.
    // double(): Converts a value to a double precision floating-point number.
    // char(): Converts an integer to its corresponding ASCII character. For example, char(97) would convert to 'a'.
    // bool(): Converts a value to a boolean (true or false).
     int p = char('a');
     cout << "The char() is used for reading ascii value:" << p << endl;

}