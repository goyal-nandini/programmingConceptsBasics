#include<iostream>
using namespace std;
int main(){
    // To read a full line of input, you can use getline instead of cin.
    // getline is a function in c++

    string name2, city;
    getline(cin, name2); // Reads a line of text from the input stream 'cin' and stores it in 'name2'
    // reads an entire line of input from standrd input(keyboard) and stores it in the string variable name2.
    // reads input until it encounters a newline character (\n).
    cout << "using 'getline' function:\n";
    cout << name2 << endl; // prints whole name
   // If you want to specify a delimiter (a character that indicates the end of the input), you can use the following syntax:
   //getline(cin, str, delimiter); // Reads input until a comma is encountered.
   
   getline(cin, city, ' '); //When you specify a delimiter in the getline function, you need to use a single character as the delimiter.
   // getline expects single character as a parameter.
   cout << "Using delimiter in 'getline' function:\n";
   cout << city;
   return 0;
}