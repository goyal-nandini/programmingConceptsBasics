// use of destructor
// The main concept here is that a class constructor is called every time an object is created, similarly as 
//the programme control leaves the current block, the objects in the block start getting destroyed and 
//destructors are called for each one of them.Note that the objects are destroyed in the reverse order of their
// creation. finally when the block 1 is exited, the destructors are called corresponding to the remaining 
//objects presence inside main.
#include<iostream>
using namespace std;

int count = 0;
class myClass{
    
    public:
    int *num = new int(36);
        myClass(){
           count++;
           cout << "constructor called " << count << endl;
        }
        ~myClass(){
            cout << "destructor called " << count << endl;
            count--;
            delete num;
        }
};

int main() {
    myClass obj1; 
    //block 1
    {
        cout << "inside block 1... \n";
        myClass obj2, obj3;
        cout << "leaving block 1... \n";
    }
    cout << "back inside main function... \n";

    myClass *objptr = new myClass;
    delete objptr;

    return 0;
}