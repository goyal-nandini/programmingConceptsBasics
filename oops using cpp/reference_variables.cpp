#include<iostream>
using namespace std;
int main() {
        int n[5] = {1, 2, 3, 4, 5};
        int &x = n[5];

        //         What is '\n'?

        // '\n' is a character literal, which is a rvalue (a temporary value that doesn't have a memory address you can modify).
        // References require an lvalue (a variable or object with a memory address) to bind to.
        // Why can't '\n' work?

        // A reference creates an alias for a variable, and a character literal like '\n' is not a variable; it’s just a temporary value stored in memory, which cannot have an alias.
        // char &a = '\n';
        const char &a = '\n';
        //or
        char q = '\n';
        char &p = q;

        cout << n[2] << a;
        cout << "New line gotte printed!" << a << p;

        int t;
        int *y;
        y = &t;
        int &m = *y;

        cout << &t << a 
        << y << a 
        << m; //m is a reference to t. However, since t is uninitialized, the value printed for m will be undefined (garbage value).

        


    return 0;
}