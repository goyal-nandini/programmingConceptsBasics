// message: here I'll be learning core concepts from book implementing them to strong my basic 
// knowledge, may be this folder include few files but all would be my learning from book 
// #The Basics

#include<iostream>
using namespace std;

int main(){

    cout << "Hello World\n";
    string name1;
    cin >> name1; // not giving full name! The issue is how cin handles input. By default, cin reads input until it encounters a space, so it only captures the first word of the name.
    cout << "using 'cin' object :\n";
    cout << name1; // prints half name
    
    return 0;
}