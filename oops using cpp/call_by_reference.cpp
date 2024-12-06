// using reference variables concept
#include<iostream>
using namespace std;

void swap(int &, int &);

int main() {
        
        int a = 2, b = 3;
        
        swap(a, b);
        cout << "in main function: " << endl;
        cout << "a: " << a << ", b: " << b << endl;
    return 0;
}

void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << "x: " << x << ", y: " << y << endl;

}