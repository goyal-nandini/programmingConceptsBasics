// #include<iostream>
// #include<string>
// using namespace std;

// class Car {
// private:
//     const int chassisNumber;  // Constant data member
//     string model;             // Model of the car

// public:
//     // Constructor with initializer list (non-empty)
//     Car(int chNumber, string carModel) : chassisNumber(chNumber), model(carModel) {
//         cout << "Car object is created with Chassis Number: " << chassisNumber << endl;
//         cout << "value of constant data member: " << chassisNumber << endl;
//     }

//     // Display function to show car details
//     void display() const {
//         cout << "Car Model: " << model << endl;
//         cout << "Chassis Number: " << chassisNumber << endl;
//     }
// };

// int main() {
//     Car car1(12345, "Toyota Corolla");
//     car1.display();

//     cout << "Changing the arguments of parameterized constrcutor" << endl;
//     Car car2(3445, "Mahendra");
//     car2.display();
    
//     return 0;
// }
 

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    const int chassisNumber;  // Constant data member
    string model;             // Model of the car

public:
    // Constructor with initializer list (non-empty)
    Car(int chNumber, string carModel) 
        : chassisNumber(chNumber), model(carModel) {
        cout << "Car object is created with Chassis Number: " << chassisNumber << endl;
    }

    // Display function to show car details
    void display() const {
        cout << "Car Model: " << model << endl;
        cout << "Chassis Number: " << chassisNumber << endl;  // Print the constant data member
    }
};

int main() {
    // Creating multiple car objects with the same chassis number
    Car car1(12345, "Toyota Corolla");
    car1.display();  // Displays details of car1

    cout << endl; // For better readability in output

    Car car2(234, "Honda Civic");
    car2.display();  // Displays details of car2

    cout << endl; // For better readability in output

    Car car3(45, "Ford Focus");
    car3.display();  // Displays details of car3

    return 0;
}

