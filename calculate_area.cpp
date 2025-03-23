#include <iostream>
#include <cmath>  // For sqrt() function
#define PI 3.14159  // Define constant for π

using namespace std;  // Using standard namespace

// Function to calculate the area of a Circle
double area(double radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a Rectangle
double area(double length, double width) {
    return length * width;
}

// Function to calculate the area of a Triangle (using Heron's formula)
double area(double a, double b, double c) {
    double s = (a + b + c) / 2;  // Semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));  // Heron's formula
}

int main() {
    int choice;
    cout << "Choose a shape to calculate area:\n";
    cout << "1. Circle\n2. Rectangle\n3. Triangle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        double r;
        cout << "Enter radius of the circle: ";
        cin >> r;
        cout << "Area of Circle: " << area(r) << endl;
    } 
    else if (choice == 2) {
        double l, w;
        cout << "Enter length and width of the rectangle: ";
        cin >> l >> w;
        cout << "Area of Rectangle: " << area(l, w) << endl;
    } 
    else if (choice == 3) {
        double a, b, c;
        cout << "Enter three sides of the triangle: ";
        cin >> a >> b >> c;

        if (a + b > c && a + c > b && b + c > a) {  // Check if valid triangle
            cout << "Area of Triangle: " << area(a, b, c) << endl;
        } else {
            cout << "Invalid triangle sides!\n";
        }
    } 
    else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
