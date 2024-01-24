#include <iostream>
#include <string>

using namespace std;

// Example of a simple C++ class
class Car {
private:
    // Private details hidden from external code
    int speed;

public:
    // Data members or attributes
    string brand;
    int year;

    // Member functions or methods
    void accelerate() {
        // Implementation details hidden
        speed += 10;
    }

    void brake() {
        // Implementation details hidden
        speed -= 5;
    }
};

int main() {
    // Creating objects of the Car class
    Car myCar;            // Creating an object without specifying attributes
    myCar.brand = "Toyota";
    myCar.year = 2022;

    Car anotherCar{"Ford", 2020};  // Creating an object with specific attributes

    // Using objects and demonstrating abstraction
    cout << "My car brand: " << myCar.brand << ", Year: " << myCar.year << endl;
    myCar.accelerate();
    cout << "Accelerating... Speed: " << myCar.speed << " km/h" << endl;

    cout << "Another car brand: " << anotherCar.brand << ", Year: " << anotherCar.year << endl;
    anotherCar.brake();
    cout << "Applying brakes... Speed: " << anotherCar.speed << " km/h" << endl;

    return 0;
}
