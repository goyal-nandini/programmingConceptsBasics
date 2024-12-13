#include<iostream>
#include<cstring>
using namespace std;
int main() {
    // char name[20];
    // cin.getline(name, 20); // object oriented programming
    // cout << name;
    // cout << "\nthe length of the string is: " << endl;
    // cout << strlen(name) << endl; // 19
    // cout << (int)name[19] << endl; // output-->0, as null character, "19" is the index which is itself a 20th character.

    // cout.write(name, 6); // output--->object

    string sentence;
    cout << "Enter a sentence: ";
    // getline() reads input from "cin" (the standard input stream) and stores it in the "sentence" variable.
    getline(cin, sentence);  // Reads the entire line
    cout << "You entered: " << sentence << endl;
    return 0;
}

// *****Key Differences Between "cin >>" and "getline()" ---->
// cin >> reads input until the first space. It doesn't capture spaces between words.
// Example: cin >> word; with input "Hello there" will only capture "Hello".

// getline(cin, sentence) captures the "entire line", including spaces, until the Enter key is pressed.
// Example: getline(cin, sentence); with input "Hello there" will capture "Hello there"


// *****getline(cin, sentence) (with std::string) captures the whole line of input without worrying about size.
// *****cin.getline(sentence, 30) (with char[]) captures up to 29 characters (since 1 character is reserved for the null terminator).