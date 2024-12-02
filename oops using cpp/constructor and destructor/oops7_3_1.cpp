//deep copy different style
#include<iostream>
#include<cstring>

using namespace std;

class myClass{
    char *name;
    char *gender;

    public:
        myClass(const char *n, const char *g){
            name = new char[strlen(n) + 1];
            gender = new char[strlen(g) + 1];

            strcpy(name, n);
            strcpy(gender, g);   
        }
        myClass(myClass & obj){
            name = new char[strlen(obj.name) + 1];
            gender = new char[strlen(obj.gender) + 1];

            strcpy(name, obj.name);
            strcpy(gender, obj.gender);

        }
        void display() const{
            cout << "name is: " << name << endl;
            cout << "gender is: " << gender << endl;
        }
        ~myClass(){
            delete[] name;
            delete[] gender;
        }
        void modify(){
                name[strlen(name)-1] = 'i';

                // Modify gender to "female"
                delete[] gender;  // Free the old memory before assigning a new value
                gender = new char[7]; // "female" requires 7 characters
                strcpy(gender, "female");
        }

};
// not adding const: 
// The warning you're seeing, *"ISO C++ forbids converting a string constant to 'char'"**, occurs because string literals like 
//"priyanshu" and "male" are of type const char[], while your constructor is expecting a char* type. This is a violation because 
//string literals are read-only, and using them in a char* type would allow accidental modification, which C++ does not allow.

// Solution:
// To fix this, you need to change the constructor's parameters to accept const char* instead of char*. This ensures that the
// string literals are treated as read-only and you won't run into issues when passing them to the constructor.

// Changes:
// The constructor now takes const char *n and const char *g instead of char *n and char *g. This ensures the string literals
// are treated as constant and prevents the warning you encountered.
// The display() function is also marked as const, ensuring that it does not modify the object when called.
int main() {
    myClass obj1("priyanshu", "male");
    myClass obj2(obj1);

    obj1.display();
    obj2.display();

    obj1.modify();

    obj1.display();
    obj2.display();


    return 0;
}