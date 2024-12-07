#include<iostream>
using namespace std;

// Forward declaration of class B
class B;

class A {
private:
    int numA;

public:
    A(int value) {
        numA = value;
    } // Constructor to initialize numA

    // Declare class B as a friend of class A
    friend class B;
};

class B {
private:
    int numB;

public:
    B(int value) {
        numB = value;
    } // Constructor to initialize numB

    // Function to access private members of class A
    int sum(A objA) {
        return objA.numA + numB;
    }
};
int main() {

    A a(23);
    B b(67);
    cout << "The value of the sum is: " << b.sum(a);
    return 0;
}