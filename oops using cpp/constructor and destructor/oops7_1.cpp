//Custom Copy Constructor
//You can define a custom copy constructor to control how objects are copied.
#include<iostream>
using namespace std;

class ocean{
    public:
    string weather;
    bool permit;
    ocean(string weather, bool permit){
        this -> weather = weather;
        this -> permit = permit;
        cout << "weather?: " <<  this -> weather << endl;
        cout << "permit?: " <<  this -> permit << endl;
        cout << this << endl;
    }
    ocean(const ocean & o){
        this -> weather = o.weather;
        this -> permit = o.permit;
        cout << "weather?(copy): " <<  this -> weather << endl;
        cout << "permit?(copy): " <<  this -> permit << endl;
        cout << this << endl;
    }
};

int main(){
    ocean o1("cloudy", 0); // calls parameterized constructor
    o1.weather = "windy";
    ocean o3(o1.weather, 1);
    ocean o2(o1); // calls custom copy constructor
    
    return 0;
}