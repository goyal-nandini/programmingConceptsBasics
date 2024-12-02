#include <iostream>
using namespace std;

void func(int x) {
    cout << "Integer function called with " << x << endl;
}

void func(int* ptr) {
    cout << "Pointer function called " << ptr << endl;
    cout << "Pointer function called " << ptr+1 << endl;
}

int main() {
    //func(NULL); // Ambiguous in function overloads, may call the integer version
    func(nullptr); // Always resolves to the pointer version
    return 0;
}
