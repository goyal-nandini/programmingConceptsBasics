//getter and setter
#include<iostream>
using namespace std;

class cars{
    // properties or data members
    string model;
    int year;
    void properties(){
        cout << "A red fictional 2006 race car who is described by John Lasseter in the Los Angeles Times" << endl;
    }

    public:
    // behaviour or member functions
    int speed(){
        return 40;
    }

    //getter and setter
    string getModel(){
        setModel();
        return model;
    }

    void setModel(){
        model = "Lightning McQueen";
    }

    int getYear(){
        return year;
    }

    void setYear(int y){
        year = y;
    }
        
    void millage();
    
};
void cars :: millage(){
    cout << "Millage is Excellent." << endl;
    cout << "Properties: "<< endl;
    //private member function access
    properties();
}

// void cars :: properties(){
//     cout << "A red fictional 2006 racecar who is described by John Lasseter in the Los Angeles Times" << endl;
// }


int main(){

    cars c1;
    cout << "Model name: " << c1.getModel() << endl;
    c1.setYear(1996);
    cout << "Year is: " << c1.getYear() << endl;
    cout << "Speed is: " << c1.speed() << " kmph" << endl;
    c1.millage();
    
    return 0;
}