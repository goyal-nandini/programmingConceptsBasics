//parameterized constructor
#include<iostream>
using namespace std;

class integer{
        int m, n;
        public:
            void add(int, int);
            integer(int, int);
};
// member function definition
void integer :: add(int x, int y){
    m = x;
    n = y;
    cout << "Sum is: " << m + n << endl;
}
// constructor definition
integer :: integer(int p, int q){
    cout << "Enter two integers: "<< endl;
    cin >> p >> q;
    add(p, q);
}

int main(){
    int s, t;
    integer int1(s, t); // implicit call
    integer int2 = integer(s, t); // explicit call
    //This explicitly constructs a temporary object integer(s, t) and then copies or moves the result to int2.
    //This is known as copy initialization.

    integer *int3 = new integer(s, t); // check oops6 for detailed study
    return 0;
}