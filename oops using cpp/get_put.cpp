#include<iostream>
using namespace std;
int main() {
    // char ch;
    // cin.get(ch); // eg. nandini
    // cout.put(ch); // output -> n as get() takes a character at a time
    // ch = cin.get(); //another way to use
    // cout.put('\n');

    char c = 0;
    int count = 0;
    //issue here, encountered below
    // while (c != '\n'){
    //     cin.get(c); // get the input until user press "enter"

    //     count++;
    //     cout.put(c);
    // }
    // cout << "the number of characters entered is: " << count << endl; //output->14(incorrect) b/c counting the newline after "nandini goyal(enter)" that's why it count 14
    
    cout.put(68); // prints D 

    cout << "Input: " << endl;
    cin.get(c);
    while(c != '\n'){
        cout.put(c);
        count++;
        cin.get(c); //nandini goyal
    }
    cout << "\nthe number of characters: " << count << endl; //output-->13(correct)   
    return 0;
}