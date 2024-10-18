// #include <iostream>
// #include <string>
// using namespace std;

// class Car {
// private:
//     const int chassisNumber;  // Constant data member
//     string model;             // Model of the car

// public:
//     // Constructor with initializer list (non-empty)
//     Car(int chNumber, string carModel) 
//         : chassisNumber(chNumber), model(carModel) {
//         cout << "Car object is created with Chassis Number: " << chassisNumber << endl;
//     }

//     // Display function to show car details
//     int display() const {  // 'const' keyword ensures this function doesn't modify the object
//         cout << "Car Model: " << model << endl;
//         cout << "Chassis Number: " << chassisNumber << endl;  // Print the constant data member
//         return chassisNumber;
//     }
// };

// int main() {
//     // Creating first car object with a specific chassis number
//     Car car1(12345, "Toyota Corolla");
//     car1.display();  // Displays details of car1

//     cout << endl; // For better readability in output

//     // Creating second car object with a different chassis number
//     Car car2(67890, "Honda Civic");
//     car2.display();  // Displays details of car2

//     cout << endl; // For better readability in output

//     // Creating third car object with another different chassis number
//     Car car3(54321, "Ford Focus");
//     car3.display();  // Displays details of car3

//     // Displaying chassis numbers to demonstrate each instance retains its value
//     cout << "After creating multiple cars:" << endl;
//     cout << "Car 1 Chassis Number: " << car1.display() << endl;
//     cout << "Car 2 Chassis Number: " << car2.display() << endl;
//     cout << "Car 3 Chassis Number: " << car3.display() << endl;

//     return 0;
// }

#include <iostream>

// Define a namespace called 'MyNamespace'
namespace MyNamespace {

    // Define a class called 'Person' within 'MyNamespace'
    class Person {
    private:
        std::string name;
        int age;

    public:
        // Constructor
        Person(std::string n, int a) {
            name = n;  // Assign the name
            age = a;   // Assign the age
            std::cout << "Constructor called: Creating " << name << ", Age: " << age << std::endl;
        }

        // Destructor
        ~Person() {
            std::cout << "Destructor called: Destroying " << name << std::endl;
        }

        // Member function to display person details
        void displayInfo(){
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }
    };

} // end of namespace MyNamespace

int main() {
    // Using the namespace to create objects
    MyNamespace::Person person1("Alice", 30);
    person1.displayInfo();

    {
        // Creating another object inside a nested scope
        MyNamespace::Person person2("Bob", 25);
        person2.displayInfo();
    } // person2 goes out of scope here, destructor is called

    MyNamespace::Person person3("Charlie", 40);
    person3.displayInfo();

    return 0;
} // person1 and person3 go out of scope here, destructors are called
