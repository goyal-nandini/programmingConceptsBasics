#include <iostream>
using namespace std; // Global namespace

// Global variable
int a = 50;

// Namespace for CSE department
namespace CSE {
    class Students {
        public:
            int b;
            Students(int value) : b(value){}
    };
    int a = 10; // Namespace-level variable
}

// Namespace for IT department
namespace IT {
    int a = 20; // Namespace-level variable
}

int main() {
    // Local variable
    int a = 40;
    
    // Creating an object of Students class from CSE namespace
    CSE::Students S1(100);

    // Displaying the local variable 'a'
    cout << "Local variable: " << a << endl;
    
    // Displaying the global variable 'a'
    cout << "Global variable: " << ::a << endl;

    // Displaying the 'a' from CSE namespace
    cout << "CSE namespace variable: " << CSE::a << endl;

    // Displaying the 'a' from IT namespace
    cout << "IT namespace variable: " << IT::a << endl;

    cout << "The value of b in student class: " << S1.b << endl;

    return 0;
}
