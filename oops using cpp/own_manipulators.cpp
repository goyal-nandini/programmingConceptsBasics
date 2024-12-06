#include<iostream>
using namespace std;

//custom manipulator
ostream& custom_separator(ostream& os){
    os << "-----"; // adds a seperator to the output
    return os; // return the stream so we can chain more operation i.e. 
//When custom_separator finishes its work(adding "-----"), it returns the same stream(here, cout).
// This allows the next part of the operation (like printing "Hello") tocontinue using the same stream(here, cout).
} 

//os is a reference to the stream(here, cout)passed when the manipulator is used.
//or
//os is like a nickname for the stream(here, cout) 

//****Example: In "cout << custom_separator;", cout is passed as os.

int main() {
    cout << custom_separator << "Hello World" << custom_separator << endl;
    return 0;
}

//std::cout is of type std::ostream&, which means it is a reference to an object(that handles output to the console) of type std::ostream.