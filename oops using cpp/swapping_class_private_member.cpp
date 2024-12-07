// use of friend function with call by reference 
// swapping private data of classes
#include<iostream>
using namespace std;
// forward declaration 
class class_2;

class class_1{
    int value_1;
    friend void exchange(class_1 &, class_2 &);
    public:
        void setValue(int data){
            this->value_1 = data;
        }
        void displayValue(){
            cout << "value 1 is: " << value_1 << endl;
        }
};
class class_2{
    int value_2;
    friend void exchange(class_1 &, class_2 &);
    public:
        void setValue(int data){
            this->value_2 = data;
        }
        void displayValue(){
            cout << "value 2 is: " << value_2 << endl;
        }    
};
void exchange(class_1 & obj_1, class_2 & obj_2){
    int temp;
    temp = obj_1.value_1;
    obj_1.value_1 = obj_2.value_2;
    obj_2.value_2 = temp;
}
int main() {
    class_1 a;
    a.setValue(23);

    class_2 b;
    b.setValue(43);

    cout << "value before exchange: " << endl;
    a.displayValue();
    b.displayValue();

    cout << "value after exchange: " << endl;
    exchange(a, b);
    a.displayValue();
    b.displayValue();

    return 0;
}