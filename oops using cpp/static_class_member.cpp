// use of static data member and member function
// counting/displaying the number of objects
#include<iostream>
using namespace std;

class myClass{
        int data;
        static int count; // static data member
        public:
            void setData(){
                data = ++count;
            }
            void showData(){
                cout << "object number: " << data << endl;
            }
            // static member function
            static int displayCount(){
                cout << "count of objects: " << count << endl;
            }
            
};
 // declaration of static data member
int myClass :: count; // by default initialized iwth 0

int main() {
        myClass c1, c2, c3;
        c1.setData();
        c1.showData();
        myClass :: displayCount();

        c2.setData();
        c2.showData();
        myClass :: displayCount();
        
        c3.setData();
        c3.showData();

        // no need of object, in calling static member function
        myClass :: displayCount();
    return 0;
}

