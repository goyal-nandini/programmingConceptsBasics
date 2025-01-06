#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function to be overridden
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    // Creating objects of derived classes
    Shape* shape1 = new Circle();  // A Circle object, but treated as a Shape
    Shape* shape2 = new Square();  // A Square object, but treated as a Shape
   
    // Both objects use the same interface (draw), but perform different actions
    shape1->draw();  // Outputs: Drawing a Circle
    shape2->draw();  // Outputs: Drawing a Square

    delete shape1;
    delete shape2;
    return 0;
}
