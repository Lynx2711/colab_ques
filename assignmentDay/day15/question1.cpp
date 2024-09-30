#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    float grade;

public:
    Student(string n, int a, float g) {
        name = n;
        age = a;
        grade = g;
    }
    void displayDetails() {
        cout << "Student Details:" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Grade: " << this->grade << endl;
    }
};

int main() {
    Student student1("Alice", 20, 85.5);
    student1.displayDetails();

    return 0;
}
