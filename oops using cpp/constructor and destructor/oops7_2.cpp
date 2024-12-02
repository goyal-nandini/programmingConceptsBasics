// shallow copy
#include<iostream>
using namespace std;
class myClass{
        private:
            int *data;
        public:
            myClass(int value){
                data = new int;
                *data = value;
            }
            // Shallow Copy Constructor (importance in .md)
            myClass(const myClass & Obj) {
                this->data = Obj.data;  // Copy the pointer (shallow copy)
                cout << "Shallow copy constructor called!" << endl;
            }
            void setValue(int item){
                *data = item;
            }
            void display(){
                cout << "Value is: " << *data << endl;
            }

            ~myClass(){
                delete data;
            }    
    };
int main() {
        myClass obj1(10);
        myClass obj2(obj1);
        obj1.display(); // 10
        obj2.display(); //10

        obj1.setValue(20);

        obj1.display(); //20
        obj2.display(); //20
        

    return 0;
}


