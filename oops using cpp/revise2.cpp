#include <iostream>
using namespace std;

// #define SQUARE(x) (x * x) // expands to (5 + 2 * 5 + 2) which gives 17
#define SQUARE(x) (x) * (x) // expands to (5 + 2) * (5 + 2) which gives 49

#define PRINT_HELLO cout << "Hello" << endl;


int main() {
    int result = SQUARE(5 + 2);  
    cout << "The result is: " << result << endl;
    PRINT_HELLO  // Prints "Hello" but does not have the return ability of a function

    return 0;
}
