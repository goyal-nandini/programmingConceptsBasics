//copy constructor: A copy constructor is a special type of constructor used in 
//object-oriented programming to create a new object as a copy of an existing object.
// It initializes the new object using the data of another object of the same class.

//Default copy constructor
//When no copy constructor is explicitly defined, C++ uses the default copy constructor, 
//which performs shallow copying.
#include<iostream>
using namespace std;

class StudentCall{
    int HstlRNo;
    string HstlName;
    int sample;

    public:
    void call();
    void outing();
    void print();
    //parameterized construtor
    StudentCall(int HstlRNo, string HstlName);
    //2. copy constructor (making ourself) or explicitly defining copy constructor.
    //next file!!
    
};
class hstl{
    int key;
    public:
    int item;
    hstl(){
        cout << "Constructor called!" << endl;
    }
    void print(){
        cout << "Hostel warden called!" << endl;
        cout << "Sample is: " << key << endl;
    }
    //getter nd setter 
    int getKey(){
        return key;
    }
    void setKey(int k){
        key = k;
    }
    
};
// constructor definition
StudentCall :: StudentCall(int HstlRNo, string HstlName){
    this -> HstlRNo = HstlRNo;
    this -> HstlName = HstlName; 
    sample = 12;  // constructor can also access private data member
}
// member function definition showing acessing private data members
void StudentCall :: print(){
    cout << "Student Hostel Room No: " << HstlRNo << endl;
    cout << "Student Hostel Name: " << HstlName << endl;
}
    
int main(){
    StudentCall S1(123, "Shakti");
    S1.print();
    //1. copy constructor (in class a "default copy constructor" get called by compiler 
    //that copies the content of object S1)
    //Direct Initialization
    StudentCall S2(S1);
    S2.print();

    // important points:
    hstl h1; // Default constructor is called, prints: "Constructor called."
    h1.setKey(76);
    h1.getKey();
    h1.print();

    h1.item = 44;
    //Copy Initialization ( The compiler rewrites it internally as class_name obj2(obj1);)
    hstl h2 = h1; // Default copy constructor is called(not default constructor), does NOT print anything
    // The message "Constructor called." will only print when the default constructor is explicitly 
    //invoked, such as during the creation of h1. It will not print during the creation of h2 because the 
    //copy constructor (not the default constructor) is invoked.
    h2.print();
    cout << h2.item << endl; // prints 44 because h2.item = h1.item; from "hstl h2 = h1;"

    return 0;
}

