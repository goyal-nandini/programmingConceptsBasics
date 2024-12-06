#include<iostream>
using namespace std;
int funct(int a, int b){
        static int c = 0; // this line executes once 
        c += 10; //when funct is called 2nd time, the value 10 would be added to 10(previous value) 
        // the value of c would be retained here in the funct function!!
        return a*b+c;
}

int main() {
        cout << funct(1, 2) << endl; // 1*2+10 = 12
        cout << funct(1, 2) << endl; // 1*2+20 = 22
        cout << funct(1, 2) << endl; // 1*2+30 = 32
        cout << funct(1, 2) << endl; // 42
    return 0;
}