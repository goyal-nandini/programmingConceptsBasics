// Distinguishing between member variables and function arguments:

// If a member variable has the same name as a function argument, use this to refer to the member variable explicitly.
#include<iostream>
class B {
private:
    int x;
    int y;

public:
    void setX(int x) {
        this->x = x; // Disambiguating member variable and parameter
    }
    void display(){
        std::cout << "Address of parameter x: " << &x << std::endl; // prints address of x(parameter)
        std::cout << "Address of member variable x: " << &(this->x) << std::endl; //prints address of x(member variable)
        std::cout << "Address of current object: " << this << std::endl; //prints address of current object here b1
        std::cout << "Address of member variable y: " << &y << std::endl;

        std::cout << "Value of member variable x: " << (this->x) << std::endl; // prints value of x(member variable)
        std::cout << "Value of parameter x: " << x << std::endl;// prints value of x as argument
    }

};