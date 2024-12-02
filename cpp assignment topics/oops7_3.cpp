//deep copy
#include<iostream>
using namespace std;

class myClass{
        string *name;
        char *gender;
        public:
            myClass(string n, char g){
                name = new string;
                gender = new char;
                *name = n;
                *gender = g;
            }
            // deep copy constructor
            myClass(myClass & obj){
                //Issue in .md
                // string *id = new string;
                // char *sex = new char;
                // *id = *obj.name;
                // *sex = *obj.gender;

                // Allocate new memory for the 'name' and 'gender' and copy the value
                // name = new string;
                // gender = new char;
                // *name = *obj.name;
                // *gender = *obj.gender;
                //or
                name = new string(*obj.name);
                gender = new char(*obj.gender);
                
                    
            }
            void display(){
                cout << "name is: " << *name << endl;
                cout << "gender is: " << *gender << endl;
            }
            void setNew(string newName, char newGender){
                *name = newName;
                *gender = newGender;
            }

            ~myClass(){
                delete name;
                delete gender;
            }
};
int main() {
        myClass obj1("raman", 'm');
        myClass obj2(obj1);

        obj1.display();
        obj2.display();

        obj1.setNew("chanchal", 'F');

        obj1.display();
        obj2.display();


    return 0;
}