// also ambiguous resolution
// preparing a academic report of a student entering data from user 
//to enter name and roll no. only
#include<iostream>
using namespace std;
class student{
    protected:
        long long roll_number;
    public:
        void put_roll_number(){
            cout << "the result for roll no." << roll_number << endl;
        }  
        void set_roll_number(long long r){
            roll_number = r;
        }  
        // abstract class by
        // pure virtual function
        // virtual void display() = 0; 
};
class test : virtual public student{
    protected:
        float sub1, sub2;
    public:
        void put_marks(){
            cout << "marks obtained:\n" <<
            "sub 1: " << sub1 << endl <<
            "sub 2: " << sub2 << endl;
        }   
        void set_score(float s1, float s2){
            sub1 = s1;
            sub2 = s2;
        } 
};
class sports : public virtual student{
    protected:
        float score;
    public:
        void put_score(){
            cout << "scores: " <<
            score << endl;
        }   
        void set_score(float s){
            score = s;
        } 
};
class result : public test, public sports{ // multiple inheritance
    float total;
    public:
        void display(){
            total = 
            score + sub1 + sub2; // these are "protected" to result class
            // these are "public" to result class
            put_roll_number();
            put_marks();
            put_score();
            cout << "result(out of 300): " << total;
        }
};
int main() {
    result r1;
    string name;
    long long roll_number;
    cout << "enter student details: \nenter name: ";
    cin >> name;
    cout << "enter roll number: ";
    cin >> roll_number;

    r1.set_roll_number(roll_number);
    // ambiguous
    // r1.set_score(89, 90);

    // ambiguity resolution
    r1.test::set_score(99, 90);
    r1.sports::set_score(80);
    r1.display();
    return 0;
}