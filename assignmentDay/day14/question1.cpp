#include<iostream>
using namespace std;
class Car {
public:
    string brandName;
    string model;
    string engine;
    int numberOfSeats;
    Car(string b, string m, string e, int seats) {
        brandName = b;
        model = m;
        engine = e;
        numberOfSeats = seats;
    }
    void displayInfo() {
        cout << "Car Information: " << endl;
        cout << "Brand Name: " << brandName << endl;
        cout << "Model: " << model << endl;
        cout << "Engine: " << engine << endl;
        cout << "Number of Seats: " << numberOfSeats << endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", "1.8L", 5);
    car1.displayInfo();
    return 0;
}
