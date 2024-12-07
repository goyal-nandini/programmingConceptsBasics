// refer from book balaguruswamy, excellent use of friend function, returning objects
#include <iostream>
using namespace std;
class complex
{
    float x, y;

public:
    complex() {}
    complex(float a)
    {
        x = y = a;
    }
    complex(float real, float img)
    {
        x = real;
        y = img;
    }
    friend complex sum(complex, complex);
    friend void show(complex);
};
complex sum(complex c1, complex c2)
{
    complex c3;
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;
    return c3;
}
void show(complex c)
{
    cout << c.x << " + " << c.y << "i" << endl;
}
int main()
{
    // direct initialization
    complex A(3.3, 4.5);
    complex B(12.4);
    complex C;

    C = sum(A, B);
    cout << "A: ";
    show(A);
    cout << "B: ";
    show(B);
    cout << "C: ";
    show(C);

    cout << endl;

    // other way to initialize values
    // copy initialization: 
    //A temporary object is created using complex(19.4, 45.23) and then "copied" into p.
    //With modern compilers, this copy is often optimized away (termed copy elision).
    // Copy elision is an optimization technique used by C++ compilers to eliminate unnecessary copying 
    //or moving of objects during object initialization

    complex p, q, r;
    p = complex(19.4, 45.23);
    q = complex(44);
    r = sum(p, q);


    cout << "p: ";
    show(p);
    cout << "q: ";
    show(q);
    cout << "r: ";
    show(r);
    
    return 0;
}